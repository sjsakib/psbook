#!/usr/bin/python3
import os
import datetime
from subprocess import check_output

ignored = ['.gitignore']

# changed = check_output(['git', 'ls-files'])
changed = check_output(['git', 'diff', '--cached', '--name-only'])
changed = changed.decode('utf-8').split('\n')


def get_target(file):
    base, ext = os.path.splitext(file)
    base = base.split('-')[0]
    base = base.lower().replace(' ', '-')
    file = base + '.md'
    return os.path.join('docs', file), ext


def write_md(code, data, ext):
    txt = ''
    if 'Approach' in data and data['Approach']:
        txt += '### '+data['Approach']+'\n\n'
    if 'des' in data:
        txt += data['des'] + '\n\n'
    txt += '\n---|---\n'
    for k, v in data.items():
        if k not in ['Approach', 'Problem', 'des', 'Author']:
            txt += (k + ' | ' + v + '\n')
    tm = datetime.datetime.now().strftime('%d %b %Y %H:%M')
    txt += 'Commit Time | ' + tm + '\n\n'

    if ext != '.md':
        txt += '```' + ext[1:] + '\n'
        txt += code + '\n'
        txt += '```\n'
    else:
        txt += code

    return data['Problem'], txt


def process_cpp(data, file_name, ext):
    lines = data.split('\n')
    i = 1
    data = {}
    data['des'] = ''
    while lines[i].startswith(' *'):
        comment = lines[i][3:]
        if ':' in comment:
            comment = comment.split(':')
            data[comment[0].strip()] = comment[1].strip()
        else:
            data['des'] += comment
        i += 1

    if not len(data):
        data['Problem'] = os.path.splitext(file_name)[0]

    code = '\n'.join(lines[i+1:])

    return write_md(code, data, ext)


def process_py(data, file_name, ext):
    parts = data.split('"""')
    try:
        comments = parts[1].split('\n')
    except IndexError:
        return write_md(data, {'Problem': os.path.splitext(file_name)[0]}, ext)

    code = '"""'.join(parts[2:])

    data = {}
    data['des'] = ''

    for line in comments:
        if ':' in line:
            line = line.split(':')
            data[line[0].strip()] = line[1].strip()
        else:
            data['des'] += line + '\n'

    return write_md(code, data, ext)


def process_data(data, file_name, ext):
    if ext == '.py':
        return process_py(data, file_name, ext)
    elif ext == '.cpp':
        return process_cpp(data, file_name, ext)
    else:
        return write_md(data, {'Problem': os.path.splitext(file_name)[0]}, ext)


cnt = 0
for file in changed:
    try:
        if not os.path.exists(file) or file.startswith('docs') or file in ignored:
            continue

        with open(file, 'r') as f:
            data = f.read()

        target, ext = get_target(file)
        tar_path, tar_file = os.path.split(target)
        name, data = process_data(data, tar_file, ext)

        if not os.path.exists(tar_path):
            os.makedirs(tar_path)

        if os.path.exists(target):
            with open(target, 'a') as f:
                f.write(data)
        else:
            with open(os.path.join(tar_path, 'index.md'), 'a+') as f:
                to_add = "* [{}]({})\n".format(name, tar_file)
                f.write(to_add)
            with open(target, 'w') as f:
                f.write('# '+name+'\n\n')
                f.write(data)
        cnt += 1
    except Exception as e:
        print("While processing", file)
        raise e

print("Building docs successful...")
print("Number of files modified - ", cnt)

print(check_output(['git', 'add', '*']))

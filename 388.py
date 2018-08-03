

def func_dic(input):
    maxlen = 0
    pathlen = {0: 0}
    for line in input.splitlines():
        print(f'dic: {pathlen}')
        print('line is: ', line)
        name = line.lstrip('\t')
        print('name is: ', name)
        depth = len(line) - len(name)
        print('depth is: ', depth)

        if '.' in name:
            maxlen = max(maxlen, pathlen[depth] + len(name))
        else:
            pathlen[depth + 1] = pathlen[depth] + len(name) + 1

    print(pathlen)
    return maxlen

#s = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"
s = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir22\n\t\tsubsubdir22\n\t\t\tfile22.ext"
##print(s)
##print(func(s))


def func_stack(input):
    stack = []
    stack.append(0)
    maxLen = 0
    for line in input.split('\n'):
        print(f'line is : {line}')
        depth = line.count('\t')
        print(f'depth is: {depth}')
        print(f'stack is: {stack}')
        while(depth + 1 < len(stack)):
            stack.pop()
        print(f'after pop stack: {stack}')
        print(len(line) - depth)
        llen = stack[-1] + len(line) - depth + 1
        stack.append(llen)

        print(f'after stack is: {stack}')
        if '.' in line:
            maxLen = max(maxLen, llen - 1)

    print(stack)
    return maxLen

##print(s)
##print(func_stack(s))

def func_array(input):
    paths = input.split('\n')
    print(paths)
    stack = [0] * (len(paths) + 1)
    print(stack)
    maxLen = 0
    for line in paths:
        print(line)
        print(stack)
        name = line.lstrip('\t')
        depth = len(line) - len(name)
        curLen = stack[depth] + len(name) + 1
        print(curLen)
        stack[depth + 1] = curLen

        if '.' in line:
            maxLen = max(maxLen, curLen - 1)

    return maxLen

##print(s)
##print(func_array(s))



## get path
def func_get_path_dic(input):
    maxlen = 0
    pathlen = {0: ''}
    for line in input.splitlines():
        print(f'dic: {pathlen}')
        print('line is: ', line)
        name = line.lstrip('\t')
        print('name is: ', name)
        depth = len(line) - len(name)
        print('depth is: ', depth)

        if '.' in name:
            print('path is: ', pathlen[depth] + '\\' + name)
            maxlen = max(maxlen, len(pathlen[depth]) + len(name))
        else:
            pathlen[depth + 1] = pathlen[depth] + '\\' + name

    print(pathlen)
    return maxlen

##print(s)
##print(func_get_path_dic(s))


def func_get_path_Stack(input):
    stack = []
    stack.append('')
    maxLen = 0
    for line in input.split('\n'):
        print(f'line is : {line}')
        depth = line.count('\t')
        print(f'depth is: {depth}')
        name = line.lstrip('\t')
        print(f'stack is: {stack}')
        while(depth + 1 < len(stack)):
            stack.pop()
        print(f'after pop stack: {stack}')
        print(len(line) - depth)
        llen = len(stack[-1]) + len(line) - depth + 1

        stack.append(stack[-1] + '\\' + name)

        print(f'after stack is: {stack}')
        if '.' in line:
            print('*********path is: ', stack[-1])
            maxLen = max(maxLen, llen - 1)

    print(stack)
    return maxLen

##print(s)
##print(func_get_path_Stack(s))



def func_get_path_array(input):
    paths = input.split('\n')
    print(paths)
    stack = [''] * (len(paths) + 1)
    print(stack)
    maxLen = 0
    for line in paths:
        print(line)
        print(stack)
        name = line.lstrip('\t')
        depth = len(line) - len(name)
        curLen = len(stack[depth]) + len(name) + 1
        print(curLen)
        #stack[depth + 1] = curLen
        stack[depth + 1] = stack[depth] + '\\' + name

        if '.' in line:
            print('path is:----', stack[depth] + '\\' + name)
            maxLen = max(maxLen, curLen - 1)

    return maxLen

print(s)
print(func_get_path_array(s))


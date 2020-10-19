from subprocess import run, PIPE, STDOUT

end = '\nexit\n;;'

class color:
   PURPLE = '\033[1;35;48m'
   CYAN = '\033[1;36;48m'
   BOLD = '\033[1;37;48m'
   BLUE = '\033[1;34;48m'
   GREEN = '\033[1;32;48m'
   YELLOW = '\033[1;33;48m'
   MAGENTA = '\033[1;31;48m'
   BLACK = '\033[1;30;48m'
   UNDERLINE = '\033[4;37;48m'
   END = '\033[1;37;0m'

error = {
    'empty': ';;',
    'no exit': 'push int32(15)\n;;',
    'random comment': 'push int;32(15)',
    'invalid instruction': 'pu',
    'no number': 'push int(aaaa)',
    'only number': '123123123123',
    'float' : 'float(15.15)',
    'float no precision': 'float(15.)',
    'float only precision': 'float(.10)',
    '4 tokens': 'push float(10.10) lol',
    'no parameters': 'push float()',
    'multiples ()': '(()()()()())',
    'overflow int8' : 'push int8(128)',
    'overflow int16': 'push int16(32768)',
    'overflow int32': 'push int32(2147483648)',
    'pop on empty stack': 'pop',
    'assert not equal': 'push int8(8)\nassert 7',
    'assert empty': 'assert 0',
    'div by 0': 'push int8(8)\npush int8(0)\n div',
    'mod by 0': 'push int8(8)\npush int8(0)\n mod',
    'mul with only 1 val': 'push int8(8)\nmul'
}

print(f'{"type":22}    {"code":5} {"stderr":15}\n')
for err, value in error.items():
    if err == 'no exit':
        p = run(['./avm'], stderr=PIPE,
        input=value, encoding='ascii')
        cut = p.stderr.replace('\n', '')
    else:
        p = run(['./avm'], stderr=PIPE,
        input=value + end, encoding='ascii')
        cut = p.stderr.replace('\n', '')
    if p.returncode == 1:
        print(f'{color.BOLD}{err:22} {color.GREEN}{p.returncode:5} 👍    {color.BLACK}{cut:15}')
    else:
        print(f'{color.BOLD}{err:22} {color.MAGENTA}{p.returncode:5} 👎    {color.BLACK}{cut:15}')


import re,math

def words(s):return re.findall(r'[^ \t]+',s)
def subseq(a,b):
 it=iter(b)
 return all(any(c==d for d in it) for c in a)
def letter(c):return 'a'<=c<='z' or 'A'<=c<='Z'
def oracle(n,args):
 s=args[0] if args else ''
 if n=='fizzbuzz':return ''.join(('fizzbuzz' if i%15==0 else 'fizz' if i%3==0 else 'buzz' if i%5==0 else str(i))+'\n' for i in range(1,101))
 if n=='paramsum':return str(len(args))+'\n'
 if n in ('str_capitalizer','rstr_capitalizer'):
  out=[]
  for s in args:
   t=s.lower();out.append(''.join(c.upper() if letter(c) and ((i==0 or t[i-1] in ' \t') if n=='str_capitalizer' else (i+1==len(t) or t[i+1] in ' \t')) else c for i,c in enumerate(t))+'\n')
  return ''.join(out) if args else '\n'
 need=3 if n in ('do_op','search_and_replace') else 2 if n in ('union','wdmatch','hidenp','pgcd') else 1
 if n=='rostring':
  w=words(s);return ' '.join(w[1:]+w[:1])+'\n' if args else '\n'
 if len(args)!=need:return '0\n' if n=='add_prime_sum' else '\n'
 if n=='first_word':return (words(s)[0] if words(s) else '')+'\n'
 if n=='last_word':return (words(s)[-1] if words(s) else '')+'\n'
 if n=='rev_print':return s[::-1]+'\n'
 if n=='repeat_alpha':return ''.join(c*((ord(c.lower())-96) if letter(c) else 1) for c in s)+'\n'
 if n=='ulstr':return ''.join(c.swapcase() if letter(c) else c for c in s)+'\n'
 if n in ('rot_13','rotone','alpha_mirror'):
  out=''
  for c in s:
   if letter(c):
    base=ord('a' if c.islower() else 'A');v=ord(c)-base
    c=chr(base+(25-v if n=='alpha_mirror' else (v+(13 if n=='rot_13' else 1))%26))
   out+=c
  return out+'\n'
 if n=='search_and_replace':return (s.replace(args[1],args[2]) if len(args[1])==len(args[2])==1 else '')+'\n'
 if n=='snake_to_camel':return re.sub(r'_([a-z])',lambda m:m[1].upper(),s)+'\n'
 if n=='camel_to_snake':return ''.join('_'+c.lower() if 'A'<=c<='Z' else c for c in s)+'\n'
 if n=='union':return ''.join(dict.fromkeys(args[0]+args[1]))+'\n'
 if n=='wdmatch':return (s if subseq(s,args[1]) else '')+'\n'
 if n=='hidenp':return ('1' if subseq(s,args[1]) else '0')+'\n'
 if n in ('epur_str','expand_str'):return (' ' if n=='epur_str' else '   ').join(words(s))+'\n'
 if n=='rev_wstr':return ' '.join(words(s)[::-1])+'\n'
 if n=='rostring':
  w=words(s);return ' '.join(w[1:]+w[:1])+'\n'
 if n=='print_hex':return format(int(s),'x')+'\n'
 if n=='tab_mult':return ''.join(f'{i} x {int(s)} = {i*int(s)}\n' for i in range(1,10))
 if n=='pgcd':return str(math.gcd(int(s),int(args[1])))+'\n'
 if n=='do_op':
  a,b=int(s),int(args[2]);op=args[1];q=abs(a)//abs(b) * (-1 if (a<0)!=(b<0) else 1) if b else 0
  return str({'+':a+b,'-':a-b,'*':a*b,'/':q,'%':a-q*b}[op])+'\n'
 if n=='add_prime_sum':
  x=int(s);return str(sum(i for i in range(2,x+1) if all(i%d for d in range(2,math.isqrt(i)+1))))+'\n'
 if n=='fprime':
  v=int(s);f=[];d=2
  if v==1:return '1\n'
  while d*d<=v:
   while v%d==0:f.append(str(d));v//=d
   d+=1
  if v>1:f.append(str(v))
  return '*'.join(f)+'\n'
 raise ValueError(n)

def cases(n):
 if n=='fizzbuzz':return [[],['ignored']]
 if n=='paramsum':return [[],['a'],['','b','c']]
 if n in ('str_capitalizer','rstr_capitalizer'):return [[],['aBC dEF\t42FOO  X!'],['','hELLo WORLD','  abc\tdeF ']]
 if n=='search_and_replace':return [[],['abcaba','a','x'],['abc','z','q'],['abc','','x'],['abc','aa','x']]
 if n=='do_op':return [[],['12','+','7'],['3','-','9'],['-5','*','3'],['-7','/','3'],['-7','%','3']]
 if n in ('union','wdmatch','hidenp'):return [[],['abc','a--b--c'],['abc','cba'],['','abc'],['aaa','aa'],['abca','bbcd']]
 if n=='pgcd':return [[],['12','18'],['17','13'],['42','42'],['1','99']]
 if n in ('add_prime_sum','print_hex','tab_mult','fprime'):
  nums={'add_prime_sum':['-3','0','1','2','10','97'],'print_hex':['0','1','15','16','255','4096'],'tab_mult':['0','1','7','12'],'fprime':['1','2','12','97','225225']}[n]
  return [[],['1','2']]+[[s] for s in nums]
 if n=='snake_to_camel':return [[],['hello'],['hello_world'],['here_is_a_word'],['a_b_c']]
 if n=='camel_to_snake':return [[],['hello'],['helloWorld'],['aBC'],['hereIsAWord']]
 if n=='rev_wstr':return [[],[''],['hello'],['one two three']]
 return [[],['a','b'],[''],['abc XYZ!'],[' \t one\t two   three \t'],['zZaA09!?']]

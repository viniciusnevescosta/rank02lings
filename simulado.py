#!/usr/bin/env python3
from pathlib import Path
import json,datetime
import tester
R=Path(__file__).resolve().parent
TASKS=[
('s01_primeira_palavra',1,'int primeira_palavra(char *s)',
'Implemente int primeira_palavra(char *s). Retorne o tamanho da primeira palavra, pulando espaços e tabs iniciais. Palavra termina em espaço, tab ou fim de string. Uma entrada sem palavras retorna 0. Funções permitidas: nenhuma.',
'CHECK(primeira_palavra("")==0);CHECK(primeira_palavra(" \t ")==0);CHECK(primeira_palavra(" \t abc de")==3);CHECK(primeira_palavra("hello")==5);CHECK(primeira_palavra("a\tb")==1);'),
('s02_pares_bits',2,'unsigned char pares_bits(unsigned char n)',
'Implemente unsigned char pares_bits(unsigned char n). Troque cada par adjacente de bits: posições 0 e 1, 2 e 3, 4 e 5, 6 e 7. A posição 0 é o bit menos significativo. Exemplos: 1 vira 2; 2 vira 1; 3 permanece 3; 128 vira 64. Funções permitidas: nenhuma.',
'for(unsigned int n=0;n<256;n++){unsigned int r=0;for(int i=0;i<8;i+=2){r+=((n>>i)&1)<<(i+1);r+=((n>>(i+1))&1)<<i;}CHECK(pares_bits(n)==r);}'),
('s03_intervalo_pares',3,'int *intervalo_pares(int start,int end,int *count)',
'Implemente int *intervalo_pares(int start,int end,int *count). Retorne um vetor alocado contendo somente os números pares entre start e end, inclusive, na direção de start para end. Escreva em *count a quantidade de elementos. Se não houver pares, retorne NULL e count 0. Em falha de malloc, retorne NULL e count 0. start/end ficam entre -10000 e 10000; count é um ponteiro válido. Exemplos: (1,6) => [2,4,6]; (4,-1) => [4,2,0]; (3,3) => NULL. Funções permitidas: malloc.',
'for(int a=-5;a<=5;a++)for(int b=-5;b<=5;b++){int count=-1;int *p=intervalo_pares(a,b,&count);int v=a,k=0;while(1){if(v%2==0)k++;if(v==b)break;v+=a<=b?1:-1;}CHECK(count==k);if(!k){CHECK(p==NULL);continue;}CHECK(p);v=a;int j=0;while(1){if(v%2==0)CHECK(p[j++]==v);if(v==b)break;v+=a<=b?1:-1;}free(p);}'),
('s04_compactar_lista',4,'t_list *compactar_lista(t_list *lst)',
'Implemente t_list *compactar_lista(t_list *lst), com o tipo fornecido em lista.h. Remova e libere nós que repetem o valor do nó imediatamente anterior, mantendo o primeiro nó de cada sequência de valores iguais. Retorne a cabeça resultante. Não remova repetições separadas por outro valor. Exemplo: [1,1,2,1,1,3,3] => [1,2,1,3]. Lista vazia retorna NULL. Os nós foram alocados individualmente; data é int. Funções permitidas: free.',
'CHECK(compactar_lista(NULL)==NULL);int vals[]={1,1,2,1,1,3,3},expected[]={1,2,1,3};t_list *head=NULL;for(int i=6;i>=0;i--){t_list *p=malloc(sizeof(*p));CHECK(p);p->data=vals[i];p->next=head;head=p;}t_list *original=head;head=compactar_lista(head);CHECK(head==original);for(int i=0;i<4;i++){CHECK(head);CHECK(head->data==expected[i]);t_list *next=head->next;free(head);head=next;}CHECK(head==NULL);')]
def main():
 state=json.loads((R/'progress.json').read_text()) if (R/'progress.json').exists() else {}
 required=[e for e in tester.ALL if not e['id'].startswith('s0')]
 pending=[e['id'] for e in required if state.get(e['id'])!=tester.fingerprint(e)]
 if pending:
  print(f'Simulado reservado: faltam {len(pending)} exercícios aprovados com o conteúdo atual. Próximo: {pending[0]}.');return
 if (R/'simulation.json').exists():print('Simulado já liberado. Fontes em simulado/. Use python3 tester.py s01_primeira_palavra.');return
 entries=[]
 for id,level,signature,subject,test in TASKS:
  folder=R/'simulado'/id;folder.mkdir(parents=True,exist_ok=True)
  include='#include <stdlib.h>\n' if level>=3 else ''
  if level==4:
   include+='#include "lista.h"\n';(folder/'lista.h').write_text('typedef struct s_list { int data; struct s_list *next; } t_list;\n')
  (folder/(id+'.c')).write_text(include+signature+'\n{\n\t/* Implement from scratch. */\n}\n')
  (folder/'ENUNCIADO.md').write_text(f'# Nível {level}\n\n{subject}\n')
  h='#include <stdio.h>\n#include <stdlib.h>\n#define CHECK(x) do{if(!(x)){fprintf(stderr,"Falha: %s\\n",#x);return 1;}}while(0)\n#include "STUDENT_SOURCE"\nint main(void){'+test+'return 0;}\n'
  (R/'tests'/(id+'.c')).write_text(h);entries.append({'id':id,'level':level,'path':str(folder.relative_to(R)),'kind':'function'})
 (R/'simulation.json').write_text(json.dumps(entries,indent=2))
 (R/'simulado/INICIO.txt').write_text(datetime.datetime.now(datetime.timezone.utc).isoformat()+'\nTreino sugerido: 180 minutos, sem consultas. Não representa duração oficial.\n')
 print('Simulado liberado: 4 exercícios em simulado/. Comece pelo nível 1. Tempo sugerido: 180 minutos. Faça a simulação com um colega ou tutor.')
if __name__=='__main__':main()

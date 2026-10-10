# Rank02lings

Aprenda a transformar ideias em código C: corrija exercícios pequenos, receba feedback no terminal e avance até um simulado com quatro níveis.

- **24 microexercícios** de conceitos, com comentários em português.
- **56 exercícios** de um banco de Rank 02, com defeitos intencionais.
- **Tester local** com comparação de saída, prazo de execução e sanitizers.
- **4 desafios inéditos** para escrever do zero após concluir a trilha.

Inspirado no ciclo de prática de Rustlings e Ziglings. O projeto é independente e não é um avaliador oficial da 42. Não exige Rust, Zig, conta em serviços externos ou assistente de IA.

## Começar

Requisitos: Python 3.9+ e Clang ou GCC com suporte a C99. Não há pacotes Python para instalar. O ambiente verificado é macOS; a integração contínua também testa Linux.

```sh
git clone https://github.com/viniciusnevescosta/rank02lings.git
cd rank02lings
git switch -c estudos/meu-nome
python3 tester.py next
```

O primeiro código está em [`conceitos/c01_contar/c01_contar.c`](conceitos/c01_contar/c01_contar.c). Leia o comentário, escreva os passos em português, corrija o corpo e teste:

```sh
python3 tester.py c01_contar --watch
```

**FALHOU inicialmente é esperado:** os exercícios começam quebrados. Ao passar, execute `python3 tester.py next` para avançar. A etapa de conceitos vem antes dos códigos da prova.

No macOS, instale o compilador com `xcode-select --install` se `cc` não existir. No Ubuntu/Debian, use `sudo apt install python3 build-essential`. Para escolher um compilador: `CC=clang python3 tester.py next`.

## Comandos

| Comando | O que faz |
|---|---|
| `python3 tester.py next` | Testa o primeiro exercício pendente |
| `python3 tester.py list` | Lista IDs, arquivos e aprovação |
| `python3 tester.py status` | Mostra o progresso |
| `python3 tester.py ft_strlen` | Testa um exercício pelo ID |
| `python3 tester.py concepts` | Testa todos os microexercícios |
| `python3 tester.py level1` | Testa o nível 1; há também level2–level4 |
| `python3 tester.py all` | Testa a trilha inteira |
| `python3 tester.py ID --watch` | Repete o teste quando o arquivo é salvo |
| `python3 simulado.py` | Libera quatro desafios após a trilha |

O código de saída do tester é 0 para aprovação e 1 para reprovação. IDs inválidos retornam 2. `Ctrl+C` encerra o modo watch. O progresso depende do conteúdo dos fontes: alterar um exercício aprovado exige retestá-lo. Progresso e simulado gerado são locais e não entram nos commits.

## Como estudar

Antes de codar, descreva entrada, saída, estado, passos, condição de parada e avanço. Faça uma tabela manual com um exemplo. Após corrigir um defeito, explique sua causa e reescreva a solução sem consultar.

Use o [plano de estudos](PLANO_ESTUDOS.md), o [caderno de raciocínio](CADERNO.md) e o [checklist dos 56 exercícios](CHECKLIST.md). O simulado tem quatro problemas inéditos, um por nível, sem dicas no código inicial. A sugestão de 180 minutos é uma escolha de treino, sem relação com a duração oficial de uma prova.

## O que significa passar

Os testes verificam compilação com avisos tratados como erros, resultados de funções, bytes exatos na saída dos programas, travamentos e falhas detectadas por AddressSanitizer/UndefinedBehaviorSanitizer. Os testes foram escritos separadamente dos códigos do banco.

**PASSOU significa passou nestes testes locais.** Não certifica aprovação oficial, Norminette, funções permitidas, ausência de todo vazamento ou comportamento em falhas artificiais de malloc. Confira o contrato em `ENUNCIADO.md`. Bibliotecas do harness não autorizam seu uso na solução entregue.

Se os sanitizers não estiverem disponíveis, `--no-sanitize` permite testar com verificação de memória reduzida. Alguns códigos de origem têm limitações além do defeito intencional, que também precisam ser corrigidas.

## Contribuir

Veja [CONTRIBUTING.md](CONTRIBUTING.md). Melhorias úteis incluem casos de borda, clareza dos comentários, novos microexercícios e relatos reproduzíveis de falhas do tester. Mantenha suas soluções no seu branch de estudo; a `main` deve continuar pronta para quem está começando.

A ferramenta, os testes e os conteúdos originais deste projeto usam a [licença MIT](LICENSE). A pasta `prova/` contém material adaptado de terceiros; veja a origem, atribuições e escopo da licença em [PROVENANCE.md](PROVENANCE.md).

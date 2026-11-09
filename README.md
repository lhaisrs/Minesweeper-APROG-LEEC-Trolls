# 💣 MineSweeper — Algoritmia e Programação

Implementação do jogo MineSweeper (Campo Minado) em linguagem C, no âmbito da unidade curricular de Algoritmia e Programação — LEEC, ISEP, 2026/2027.

## 1. Objetivo do projeto

Desenvolver uma aplicação em C capaz de gerar e apresentar um tabuleiro de MineSweeper, distribuindo bombas aleatoriamente e calculando a quantidade de bombas existentes nas casas vizinhas.

Numa segunda fase, implementar a mecânica do jogo, permitindo ao utilizador revelar casas, colocar bandeiras e acompanhar o estado da partida.

## 2. Estrutura do projeto

```text
MineSweeper/
│
├── main.c
│
├── tabuleiro.h
├── tabuleiro.c
│
├── jogo.h
├── jogo.c
│
└── README.txt
```

### Responsabilidade dos módulos

| Ficheiro | Responsabilidade |
|---|---|
| `main.c` | Inicialização e controlo do fluxo principal da aplicação. |
| `tabuleiro.h` | Definição das estruturas e declaração das funções relacionadas com o tabuleiro. |
| `tabuleiro.c` | Inicialização do tabuleiro, distribuição das bombas, cálculo dos vizinhos e apresentação da solução. |
| `jogo.h` | Declaração das funções relacionadas com a mecânica do jogo. |
| `jogo.c` | Gestão das jogadas, revelação de casas, bandeiras e condições de vitória ou derrota. |
| `README.md` | Documentação do projeto e acompanhamento do cronograma de desenvolvimento. |
| `README.txt` | Documentação do projeto solicitada para a entrega do projecto. |

## 3. Cronograma de desenvolvimento

Duração prevista: **4 semanas**

Metodologia: desenvolvimento incremental, organizado em quatro Sprints.

---

### Sprint 1 — Planeamento e estruturação do projeto

**Período:** Semana 1

**Objetivo:** Preparar a estrutura do projeto e implementar a base de representação e inicialização do tabuleiro.

#### Tarefas

- [x] Criar a estrutura de diretórios e ficheiros do projeto.
- [ ] Definir a estrutura `s_casa` e o tipo associado `t_casa`.
- [ ] Definir as dimensões do tabuleiro (`NROWS` e `NCOLS`).
- [ ] Definir o número de bombas (`NBOMBS`).
- [ ] Definir a representação do tabuleiro através de um vetor de estruturas.
- [ ] Implementar a inicialização do tabuleiro.
- [ ] Implementar a identificação dos índices das oito casas vizinhas.
- [ ] Tratar os limites do tabuleiro e as posições sem vizinhos.
- [ ] Realizar testes de inicialização e identificação de vizinhos.

#### Entregáveis

- Estrutura inicial do projeto.
- Representação do tabuleiro implementada.
- Inicialização das casas.
- Identificação dos vizinhos de cada posição.

#### Critérios de aceitação

- [ ] O projeto encontra-se organizado nos módulos definidos.
- [ ] O tabuleiro é inicializado corretamente.
- [ ] Todas as casas possuem os seus índices de vizinhos corretamente identificados.
- [ ] Os cantos, extremidades e posições interiores são tratados corretamente.

---

### Sprint 2 — Geração e processamento do tabuleiro

**Período:** Semana 2

**Objetivo:** Implementar a lógica principal de geração do MineSweeper e concluir os requisitos obrigatórios do enunciado.

#### Tarefas

- [ ] Implementar a distribuição aleatória das bombas.
- [ ] Garantir que não existem bombas duplicadas na mesma posição.
- [ ] Validar a quantidade total de bombas distribuídas.
- [ ] Implementar o cálculo do número de bombas vizinhas de cada casa.
- [ ] Garantir que as casas com bombas não recebem valores de contagem.
- [ ] Implementar a apresentação do tabuleiro solução.
- [ ] Realizar testes com diferentes dimensões e quantidades de bombas.
- [ ] Validar os resultados da geração do tabuleiro.

#### Entregáveis

- Distribuição aleatória das bombas.
- Cálculo das bombas vizinhas.
- Apresentação do tabuleiro solução.

#### Critérios de aceitação

- [ ] A quantidade de bombas corresponde à configuração definida.
- [ ] Não existem bombas duplicadas.
- [ ] Os valores das casas correspondem ao número real de bombas vizinhas.
- [ ] O tabuleiro solução é apresentado corretamente.
- [ ] Os testes realizados apresentam resultados consistentes.

**Marco:** Conclusão da fase obrigatória do trabalho prático.

---

### Sprint 3 — Implementação da mecânica do jogo

**Período:** Semana 3

**Objetivo:** Desenvolver a interação com o utilizador e implementar a segunda fase do MineSweeper.

#### Tarefas

- [ ] Definir a representação visual do tabuleiro com todas as casas ocultas.
- [ ] Separar o estado real do tabuleiro do estado apresentado ao jogador.
- [ ] Implementar a leitura do tipo de interação (`L` ou `R`).
- [ ] Implementar a leitura das coordenadas da jogada (linha e coluna).
- [ ] Implementar a validação das coordenadas introduzidas.
- [ ] Implementar a revelação de casas através do clique esquerdo (`L`).
- [ ] Implementar a colocação de bandeiras através do clique direito (`R`).
- [ ] Implementar a remoção de bandeiras.
- [ ] Atualizar o contador de bombas restantes.
- [ ] Implementar a condição de derrota.
- [ ] Implementar a condição de vitória.
- [ ] Realizar testes das diferentes interações do jogador.

#### Entregáveis

- Tabuleiro interativo.
- Sistema de jogadas.
- Sistema de bandeiras.
- Controlo do estado da partida.
- Condições de vitória e derrota.

#### Critérios de aceitação

- [ ] O jogador consegue visualizar inicialmente todas as casas ocultas.
- [ ] As jogadas são processadas de acordo com o comando introduzido.
- [ ] As casas reveladas apresentam os valores correspondentes.
- [ ] As bandeiras podem ser colocadas e removidas.
- [ ] As jogadas inválidas são rejeitadas.
- [ ] O jogo termina corretamente quando o jogador ganha ou perde.

---

### Sprint 4 — Testes, integração e finalização

**Período:** Semana 4

**Objetivo:** Validar o funcionamento global da aplicação, corrigir eventuais problemas e garantir a qualidade do código desenvolvido.

#### Tarefas

- [ ] Integrar e validar todos os módulos do projeto.
- [ ] Testar a inicialização do tabuleiro.
- [ ] Testar diferentes distribuições de bombas.
- [ ] Testar o cálculo de bombas vizinhas.
- [ ] Testar as jogadas do utilizador.
- [ ] Testar a colocação e remoção de bandeiras.
- [ ] Testar as condições de vitória e derrota.
- [ ] Testar entradas inválidas e situações limite.
- [ ] Corrigir erros identificados durante os testes.
- [ ] Rever a organização e a responsabilidade das funções.
- [ ] Rever os comentários e a legibilidade do código.
- [ ] Realizar uma compilação final.
- [ ] Validar os ficheiros necessários para entrega.

#### Entregáveis

- Versão final do MineSweeper.
- Código-fonte organizado e validado.
- Funcionalidades obrigatórias e facultativas implementadas, conforme o âmbito definido.
- Conjunto de testes realizados.

#### Critérios de aceitação

- [ ] O programa compila sem erros.
- [ ] Todas as funcionalidades obrigatórias estão implementadas.
- [ ] As funcionalidades facultativas implementadas funcionam corretamente.
- [ ] Os principais cenários de teste foram validados.
- [ ] O código está organizado, comentado e legível.
- [ ] Os ficheiros de código-fonte estão preparados para entrega.

---

## 4. Funcionalidades do projeto

### Fase 1 — Funcionalidades obrigatórias

- [ ] Configuração das dimensões do tabuleiro.
- [ ] Configuração do número de bombas.
- [ ] Distribuição aleatória das bombas.
- [ ] Cálculo das bombas vizinhas.
- [ ] Apresentação do tabuleiro solução.

### Fase 2 — Funcionalidades facultativas

- [ ] Apresentação do tabuleiro com casas ocultas.
- [ ] Interação através dos comandos `L` e `R`.
- [ ] Revelação de casas.
- [ ] Colocação e remoção de bandeiras.
- [ ] Atualização do número de bombas restantes.
- [ ] Deteção de vitória.
- [ ] Deteção de derrota.

## 5. Estratégia de testes

A validação será realizada incrementalmente, durante cada Sprint.

| Área | Cenários de teste |
|---|---|
| Inicialização | Diferentes dimensões do tabuleiro. |
| Vizinhos | Casas centrais, cantos e extremidades. |
| Bombas | Distribuição e ausência de duplicações. |
| Contagem | Casas com zero a oito bombas vizinhas. |
| Apresentação | Tabuleiro solução e tabuleiro oculto. |
| Jogadas | Cliques válidos e inválidos. |
| Bandeiras | Colocação e remoção. |
| Estado do jogo | Vitória e derrota. |

## 6. Critério de conclusão do projeto

O projeto será considerado concluído quando:

1. Todos os requisitos obrigatórios estiverem implementados.
2. A fase facultativa estiver implementada e validada, caso seja desenvolvida.
3. Os testes previstos tiverem sido executados.
4. O código estiver organizado em funções e estruturas, de acordo com as normas do trabalho.
5. A aplicação compilar e executar corretamente.

---

**Unidade Curricular:** Algoritmia e Programação  
**Curso:** Licenciatura em Engenharia Eletrotécnica e de Computadores  
**Instituição:** Instituto Superior de Engenharia do Porto (ISEP)  
**Ano letivo:** 2026/2027
**Estudantes:** Lhaís Silva, Jorge Leitão e Tiago Marques
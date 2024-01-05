#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef struct {
  char pergunta[200];
  char opcoes[3][200];
  char resposta_correta;
  char dica[200];
} Pergunta;

void randomizarPerguntas(Pergunta perguntas[], int numPerguntas) {
  int i;
  srand(time(NULL)); // inicio da semente de gerador de números, NULL retorna o valor do tempo atual
  for (i = numPerguntas - 1; i > 0; i--) {
    int j = rand() % (i + 1); // essa linha gera um número aleatorio 'j' entre 0 e i, % usado para garantir que j seja sempre válido
    Pergunta temp = perguntas[i]; // troca de posições
    perguntas[i] = perguntas[j];
    perguntas[j] = temp;
  }
}

int main() {
  char resposta;
  char nome[50];
  int i;
  int j;

  setlocale(LC_ALL, "");
  printf("Qual seu nome? ");
  fgets(nome, sizeof(nome), stdin);
  nome[strlen(nome) - 1] = '\0'; // remove o carectere da nova linha(\n) e o substitui por um carectere nulo(\0)
  printf("Bem-vindo(a) ao GeoQuiz! %s\n", nome);

  Pergunta perguntas[10];

  strcpy(perguntas[0].pergunta, "O que é Geografia?");
  strcpy(perguntas[0].opcoes[0], "A ciência que estuda os seres humanos e suas "
                                 "relações com o meio ambiente.");
  strcpy(perguntas[0].opcoes[1],
         "A ciência que estuda a Terra e sua superfície.");
  strcpy(perguntas[0].opcoes[2],
         "A ciência que estuda a composição química dos seres vivos.");
  perguntas[0].resposta_correta = 'b';
  strcpy(perguntas[0].dica, "Dica: Envolve o estudo do planeta em que vivemos.");

  strcpy(perguntas[1].pergunta, "Qual é a finalidade da Geografia?");
  strcpy(perguntas[1].opcoes[0],
         "Entender a relação entre os seres humanos e a natureza.");
  strcpy(perguntas[1].opcoes[1], "Estudar a história das civilizações.");
  strcpy(perguntas[1].opcoes[2], "Investigar a composição da Terra.");
  perguntas[1].resposta_correta = 'a';
  strcpy(perguntas[1].dica, "Dica: A Geografia busca compreender a relação "
                            "entre os seres humanos e a natureza.");

  strcpy(perguntas[2].pergunta,
         "O que significa a relação Ser Humano/Natureza/Sociedade?");
  strcpy(perguntas[2].opcoes[0],
         "A forma como as pessoas interagem com a natureza ao longo do tempo.");
  strcpy(perguntas[2].opcoes[1], "A relação entre diferentes países do mundo.");
  strcpy(perguntas[2].opcoes[2],
         "A relação entre diferentes culturas no mundo.");
  perguntas[2].resposta_correta = 'a';
  strcpy(perguntas[2].dica, "Dica: Refere-se à interação das pessoas com o "
                            "ambiente ao longo do tempo.");

  strcpy(perguntas[3].pergunta, "O que é o trabalho e qual sua importância na "
                                "transformação do espaço geográfico?");
  strcpy(perguntas[3].opcoes[0], "O trabalho é o que fazemos para ganhar "
                                 "dinheiro, não tem relação com a geografia.");
  strcpy(perguntas[3].opcoes[1],
         "O trabalho é uma das formas pelas quais os seres humanos transformam "
         "a natureza, e a geografia estuda essas transformações.");
  strcpy(perguntas[3].opcoes[2],
         "O trabalho é a atividade que praticamos nas horas vagas.");
  perguntas[3].resposta_correta = 'b';
  strcpy(perguntas[3].dica,
         "Dica: O trabalho humano transforma o espaço geográfico e é "
         "fundamental para o desenvolvimento das sociedades.");

  strcpy(perguntas[4].pergunta, "O que é urbanização e quais são os problemas "
                                "ambientais decorrentes dela?");
  strcpy(perguntas[4].opcoes[0],
         "Processo de migração de pessoas do campo para a cidade; aumento da "
         "poluição e escassez de recursos naturais.");
  strcpy(perguntas[4].opcoes[1],
         "Processo de preservação ambiental em áreas urbanas; aumento da "
         "qualidade de vida e diminuição da poluição.");
  strcpy(perguntas[4].opcoes[2],
         "Processo de industrialização em áreas rurais.");
  perguntas[4].resposta_correta = 'a';
  strcpy(perguntas[4].dica,
         "Dica: Urbanização é o processo de crescimento e desenvolvimento das "
         "cidades, trazendo consigo desafios ambientais.");

  strcpy(perguntas[5].pergunta,
         "O que é uma coordenada geográfica e qual a sua importância?");
  strcpy(
      perguntas[5].opcoes[0],
      "Pontos turísticos de uma cidade, utilizada para atração de visitantes.");
  strcpy(perguntas[5].opcoes[1],
         "Localização de praias, utilizada para mapeamento de áreas de banho.");
  strcpy(perguntas[5].opcoes[2], "Sistema de referência espacial, utilizada "
                                 "para localização exata de um ponto na Terra.");
  perguntas[5].resposta_correta = 'c';
  strcpy(perguntas[5].dica,
         "Dica: Coordenadas geográficas são sistemas de referência espacial "
         "utilizados para localização precisa na Terra.");

  strcpy(perguntas[6].pergunta,
         "Quais são as principais características do cerrado brasileiro?");
  strcpy(perguntas[6].opcoes[0],
         "Vegetação rasteira, solo fértil e clima úmido.");
  strcpy(perguntas[6].opcoes[1],
         "Vegetação de gramíneas, solo pobre e clima quente e seco.");
  strcpy(perguntas[6].opcoes[2],
         "Vegetação arbórea, solo rochoso e clima frio e úmido.");
  perguntas[6].resposta_correta = 'b';
  strcpy(perguntas[6].dica, "Dica: O cerrado brasileiro é caracterizado por "
                            "vegetação de gramíneas, clima quente e seco.");

  strcpy(perguntas[7].pergunta,
         "Quais são os biomas brasileiros e suas características?");
  strcpy(perguntas[7].opcoes[0],
         "Floresta Amazônica - clima úmido e quente; Cerrado - clima seco e "
         "quente; Caatinga - clima seco e quente.");
  strcpy(perguntas[7].opcoes[1],
         "Mata Atlântica - clima úmido e temperado; Pampa - clima frio e seco; "
         "Pantanal - clima úmido e quente.");
  strcpy(perguntas[7].opcoes[2],
         "Floresta Amazônica - clima úmido e quente; Mata Atlântica - clima "
         "úmido e temperado; Cerrado - clima seco e quente.");
  perguntas[7].resposta_correta = 'c';
  strcpy(perguntas[7].dica,
         "Dica: O Brasil possui biomas como a Floresta Amazônica, Mata "
         "Atlântica e Cerrado, cada um com suas particularidades.");

  strcpy(
      perguntas[8].pergunta,
      "O que é um ecossistema e qual a sua importância para a vida na Terra?");
  strcpy(perguntas[8].opcoes[0],
         "Sistema de computador que ajuda a proteger o meio ambiente; sem "
         "importância para a vida na Terra.");
  strcpy(perguntas[8].opcoes[1], "Sistema formado apenas por plantas; sem "
                                 "importância para a vida na Terra.");
  strcpy(perguntas[8].opcoes[2],
         "Sistema formado por seres vivos e ambiente; responsável pela "
         "manutenção da vida e equilíbrio dos ecossistemas.");
  perguntas[8].resposta_correta = 'c';
  strcpy(perguntas[8].dica,
         "Dica: Ecossistema é um sistema formado por seres vivos e o ambiente, "
         "essencial para a manutenção da vida e equilíbrio ecológico.");

  strcpy(perguntas[9].pergunta, "O que é a Camada de Ozônio e qual a sua "
                                "importância para a vida na Terra?");
  strcpy(perguntas[9].opcoes[0],
         "Camada da atmosfera que protege a Terra dos raios ultravioletas; "
         "importante para a manutenção da vida e prevenção de doenças de pele.");
  strcpy(perguntas[9].opcoes[1],
         "Camada da atmosfera responsável pelo aquecimento global; prejudicial "
         "para a manutenção da vida na Terra.");
  strcpy(perguntas[9].opcoes[2],
         "Camada da atmosfera que emite radiação ultravioleta; sem importância "
         "para a vida na Terra.");
  perguntas[9].resposta_correta = 'a';
  strcpy(perguntas[9].dica,
         "Dica: A Camada de Ozônio protege a Terra dos raios ultravioleta, "
         "sendo importante para a saúde e preservação do meio ambiente."
    );

  randomizarPerguntas(perguntas, 10);

  for (i = 0; i < 10; i++) { // o for ira percorrer por todas as perguntas  
    while (1) {
      printf("\nPergunta %d: %s\n", i + 1, perguntas[i].pergunta);
      for (j = 0; j < 3; j++) {
        printf("%c) %s\n", 'a' + j, perguntas[i].opcoes[j]);
      }
      printf("Resposta: ");
      scanf(" %c", &resposta);
      resposta = tolower(resposta);
      fflush(stdin);
      if (resposta == perguntas[i].resposta_correta) {
        printf("Resposta correta! Continue assim! %s\n", nome);
        sleep(5);
        break;
      } else {
        printf("Resposta incorreta. Tente novamente em alguns segundos %s\n", nome);
        sleep(10);

        int stop; // variavel p/ impedir o sistema de ler qualquer coisa antes dos 10 segundos
        while ((stop =  getchar()) != '\n' && stop != EOF) {}

    #ifdef _WIN32
        system ("cls"); // windows
    #else
        system("clear"); // linux\mac
    #endif
        printf("%s\n", perguntas[i].dica); // Exibe a dica para o usuário
      }
    }

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
  }

  return 0;
}
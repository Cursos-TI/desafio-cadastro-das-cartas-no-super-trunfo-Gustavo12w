#include <stdio.h>

typedef struct {
    char nome[50];
    char estado[50];
    int codigo;
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder;
} Carta;


float calcularDensidadePopulacional(unsigned long int populacao, float area) {
    return (area > 0) ? (float)populacao / area : 0;
}

float calcularPibPerCapita(unsigned long int populacao, float pib) {
    return (populacao > 0) ? pib / populacao : 0;
}


float calcularSuperPoder(Carta carta) {
   
    return (float)carta.populacao + carta.area + carta.pib + carta.pontosTuristicos
           + carta.pibPerCapita + (1.0 / carta.densidadePopulacional);
}

int compararAtributos(float atributo1, float atributo2, int isDensidade) {
    if (isDensidade) {
       
        return atributo1 < atributo2; 
    }

    return atributo1 > atributo2;
}

void compararCartas(Carta carta1, Carta carta2) {
    printf("Comparação de Cartas:\n");

    printf("População: Carta 1 venceu (%d)\n", compararAtributos(carta1.populacao, carta2.populacao, 0));
    printf("Área: Carta 1 venceu (%d)\n", compararAtributos(carta1.area, carta2.area, 0));
    printf("PIB: Carta 1 venceu (%d)\n", compararAtributos(carta1.pib, carta2.pib, 0));
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", compararAtributos(carta1.pontosTuristicos, carta2.pontosTuristicos, 0));
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", compararAtributos(carta1.densidadePopulacional, carta2.densidadePopulacional, 1));
    printf("PIB per Capita: Carta 1 venceu (%d)\n", compararAtributos(carta1.pibPerCapita, carta2.pibPerCapita, 0));
    printf("Super Poder: Carta 1 venceu (%d)\n", compararAtributos(carta1.superPoder, carta2.superPoder, 0));
}

int main() {
    Carta carta1, carta2;


    printf("Digite os dados da Carta 1:\n");
    printf("Nome: ");
    scanf("%s", carta1.nome);
    printf("Estado: ");
    scanf("%s", carta1.estado);
    printf("Código: ");
    scanf("%d", &carta1.codigo);
    printf("População: ");
    scanf("%lu", &carta1.populacao);
    printf("Área: ");
    scanf("%f", &carta1.area);
    printf("PIB: ");
    scanf("%f", &carta1.pib);
    printf("Pontos turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);


    carta1.densidadePopulacional = calcularDensidadePopulacional(carta1.populacao, carta1.area);
    carta1.pibPerCapita = calcularPibPerCapita(carta1.populacao, carta1.pib);
    carta1.superPoder = calcularSuperPoder(carta1);


    printf("\nDigite os dados da Carta 2:\n");
    printf("Nome: ");
    scanf("%s", carta2.nome);
    printf("Estado: ");
    scanf("%s", carta2.estado);
    printf("Código: ");
    scanf("%d", &carta2.codigo);
    printf("População: ");
    scanf("%lu", &carta2.populacao);
    printf("Área: ");
    scanf("%f", &carta2.area);
    printf("PIB: ");
    scanf("%f", &carta2.pib);
    printf("Pontos turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);


    carta2.densidadePopulacional = calcularDensidadePopulacional(carta2.populacao, carta2.area);
    carta2.pibPerCapita = calcularPibPerCapita(carta2.populacao, carta2.pib);
    carta2.superPoder = calcularSuperPoder(carta2);


    compararCartas(carta1, carta2);

    return 0;
}
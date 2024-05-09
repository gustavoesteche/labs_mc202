typedef struct trabalhador{
    int ocpd; // determina se ele está ocupado
    int t_falta; // quanto tempo falta para a atividade acabar
    int *t_prox; // guarda o tempo necessário para a próxima atividade
    int recebeu, liberou; // se ele recebeu ou liberou peças
}trab;

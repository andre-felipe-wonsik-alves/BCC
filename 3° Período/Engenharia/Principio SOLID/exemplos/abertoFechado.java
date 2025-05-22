interface Formatador {
   String format(data);
}

String formatadorDeDatas(Date data) implements Formatador{
   return data.format();
}

void imprimeDataContratacao(Funcionario func, Formatador formatador){
   Date data = func.getDataContratacao();
   String dataFormatada = formatador.format(data);
   System.out.println(msg);
}

package binary.tree;

public class ArvoreBinaria {
	
	private No raiz;
	private int tamanho=0;

	public void add(No umNo) {
		if(raiz == null)
			raiz = umNo;
		else 
			raiz.addNo(umNo);
		tamanho++;
	}

	public int tamanho() {
		return tamanho;
	}

	public int getValorRaiz() {
		return raiz.getValor();
	}

	public No getRaiz() {
		return raiz;
	}
	
}

package binary.tree;

public class No {

	private int valor;
	private No direita;
	private No esquerda;

	public No(int i) {
		valor = i;
	}

	public int getValor() {
		return valor;
	}

	public No getDireita() {
		return direita;
	}

	public No getEsquerda() {
		return esquerda;
	}

	@Override
	public String toString() {
		return "" + getValor();
	}

	public void addNo(No umNo) {
		if(umNo.getValor() < getValor()){
			if(esquerda == null)
				esquerda = umNo;
			else
				esquerda.addNo(umNo);
		} 
		else {
			if(direita == null)
					direita = umNo;
			else
				direita.addNo(umNo);
		}
		
	}
}

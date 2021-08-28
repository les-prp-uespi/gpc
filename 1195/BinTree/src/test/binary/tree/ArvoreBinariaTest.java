package binary.tree;

import static org.junit.Assert.assertTrue;

import org.junit.Test;

public class ArvoreBinariaTest{


    @Test 
    public void testInserirNo(){
    	ArvoreBinaria a = new ArvoreBinaria();    	
    	a.add(new No(1));
    	assertTrue(a.tamanho()==1);
    }
    
    @Test 
    public void testInserirDoisNos(){
    	ArvoreBinaria a = new ArvoreBinaria();    	
    	a.add(new No(1));
    	a.add(new No(2));
    	assertTrue(a.tamanho()==2);
    	assertTrue(a.getValorRaiz() == 1);
    }
    
    @Test 
    public void testInserirTresNos(){
    	ArvoreBinaria a = new ArvoreBinaria();    	
    	a.add(new No(1));
    	a.add(new No(3));
    	a.add(new No(2));
    	No raiz  = a.getRaiz();
    	
    	assertTrue("deveria ser 3", raiz.getDireita().getValor()==3);
    	assertTrue(raiz.getEsquerda().getValor()==2);
    	assertTrue(a.getValorRaiz() == 1);
    }
}
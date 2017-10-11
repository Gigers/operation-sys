package thread;

/*
 * Feito com o acompanhamento das aulas da Loiane Groiner
 */

public class Principal {

	public static void main(String[] args) {

		sThread thread = new sThread("Thread #1", 3);
		sThread thread2 = new sThread("Thread #2", 7);
		thread.start();
		thread2.start();
	}

}

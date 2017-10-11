package thread;

public class sThread extends Thread {

	private String nome;
	private int tempo;

	public sThread(String nome, int tempo) {
		this.nome = nome;
		this.tempo = tempo;
		start();
	}

	@Override
	public void run() {
		System.out.println("Executando a thread");

		try {

			for (int i = 0; i < 6; i++) {
				System.out.println(this.nome + " Contador: " + i);
				Thread.sleep(this.tempo * 100);
			}

		} catch (InterruptedException e) {
			e.printStackTrace();
		}

	}

}

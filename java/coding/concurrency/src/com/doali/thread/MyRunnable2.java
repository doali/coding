package com.doali.thread;

public class MyRunnable2 implements Runnable {

    private int compteur;
    private boolean statut = true;

    public MyRunnable2(final int compteur) {
        this.compteur = compteur;
    }

    public void stop() {
        this.statut = false;
    }

    @Override
    public void run() {
        while (statut) {
            this.compteur++;
            System.out.print("Thread:" + Thread.currentThread().getName());
            System.out.println("\t" + this.compteur);
        }
    }
}

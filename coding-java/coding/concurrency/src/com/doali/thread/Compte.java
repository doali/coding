package com.doali.thread;

public class Compte {
    private double solde;

    public Compte() {

    }

    public void retirer(double montant) {
        if (this.solde > 0) {
            this.solde -= montant;
        }
    }

    public void deposer(double montant) {
        this.solde += montant;
    }

    public String toString() {
        return "{solde: " + this.solde + "}";
    }
}

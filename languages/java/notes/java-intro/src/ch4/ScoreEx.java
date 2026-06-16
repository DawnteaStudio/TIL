package ch4;

public class ScoreEx {
    static void main() {
        int score = 44;
        if (score >= 90)
            System.out.println("A");
        else if (score >= 80) {
            System.out.println("B");
        } else if (score >= 70) {
            System.out.println("C");
        } else if (score >= 60) {
            System.out.println("D");
        } else {
            System.out.println("F");
        }
    }
}

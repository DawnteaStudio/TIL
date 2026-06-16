package ch8;

public class ArrayEx1 {
    static void main() {
        int[] students = new int[5];
        int total = 0;

        for (int i = 0; i < 5; i++) {
            students[i] = 90 - 10 * i;
            total += students[i];
        }

        double average = (double) total / 5;
        System.out.println("점수 총합 : " + total);
        System.out.println("점수 평균 : " + average);
    }
}

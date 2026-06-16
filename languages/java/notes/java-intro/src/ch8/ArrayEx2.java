package ch8;

import java.util.Scanner;

public class ArrayEx2 {
    static void main() {
        Scanner scanner = new Scanner(System.in);

        System.out.println("5개의 정수를 입력하세요:");
        int[] numbers = new int[5];
        for (int i = 0; i < 5; i++) {
            numbers[i] = scanner.nextInt();
        }
        System.out.println("출력");
        for (int i = 0; i < 5; i++) {
            System.out.print(numbers[i]);
            if (i != 4)
                System.out.print(", ");
        }
    }
}

package ch7;

import java.util.Scanner;

public class ScannerEx1 {
    static void main() {
        Scanner scanner = new Scanner(System.in);

        System.out.print("당신의 이름을 입력하세요 :");
        String name = scanner.nextLine();
        System.out.print("당신의 나이을 입력하세요 :");
        int age = scanner.nextInt();
        System.out.println("당신의 이름은 " + name + "이고, 나이는 " + age + "살입니다.");
    }
}

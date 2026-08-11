package ch2;

import java.util.Scanner;

public class ProductOrderMain3 {
    static void main() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("입력할 주문의 개수를 입력하세요: ");
        int cnt = scanner.nextInt();
        scanner.nextLine();
        ProductOrder[] orders = new ProductOrder[cnt];

        for (int i = 1; i <= cnt; i++) {
            System.out.println(i + "번째 주문 정보를 입력하세요.");
            System.out.print("상품명: ");
            String name = scanner.nextLine();
            System.out.print("가격: ");
            int price = scanner.nextInt();
            System.out.print("수량: ");
            int quantity = scanner.nextInt();
            scanner.nextLine();

            orders[i - 1] = createOrder(name, price, quantity);
        }
        printOrder(orders);
        System.out.println("total is " + getTotalAmount(orders));
    }

    static ProductOrder createOrder(String productName, int price, int quantity) {
        ProductOrder order = new ProductOrder();
        order.productName = productName;
        order.price = price;
        order.quantity = quantity;
        return order;
    }

    static void printOrder(ProductOrder[] orders) {
        int size = orders.length;

        for (int i = 0; i < size; i++) {
            System.out.println((i + 1) + "th " + orders[i].productName + " and price is " + orders[i].price + " and quantity is " + orders[i].quantity);
        }
    }

    static int getTotalAmount(ProductOrder[] orders) {
        int total = 0;

        for (ProductOrder order : orders) {
            total += order.price * order.quantity;
        }
        return total;
    }
}

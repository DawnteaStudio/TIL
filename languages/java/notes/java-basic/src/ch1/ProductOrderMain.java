package ch1;

public class ProductOrderMain {
    static void main() {
        ProductOrder[] orders = new ProductOrder[3];

        ProductOrder tofu = new ProductOrder();
        ProductOrder kimchi = new ProductOrder();
        ProductOrder cola = new ProductOrder();

        tofu.productName = "두부";
        tofu.price = 2000;
        tofu.quantity = 2;

        kimchi.productName = "김치";
        kimchi.price = 5000;
        kimchi.quantity = 1;

        cola.productName = "콜라";
        cola.price = 1500;
        cola.quantity = 2;

        orders[0] = tofu;
        orders[1] = kimchi;
        orders[2] = cola;

        int total = 0;
        for (ProductOrder order : orders) {
            System.out.println("상품명: " + order.productName + ", 가격: " + order.price + ", 수량: " + order.quantity);
            total += order.price * order.quantity;
        }
        System.out.println("총 결제 금액: " + total);
    }
}

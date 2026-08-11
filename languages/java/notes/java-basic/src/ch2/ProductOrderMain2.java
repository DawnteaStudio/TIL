package ch2;

public class ProductOrderMain2 {
    static void main() {
        ProductOrder[] orders = new ProductOrder[10];
        for (int i = 0; i < 10; i++) {
            orders[i] = createOrder("order" + i, 10 * i, 3 + i);
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
            total += order.price;
        }
        return total;
    }
}

import java.util.Scanner;

public class Main_1 {
    public static class Product {
        String name;
        int amnt;
        Product(String name, int amnt) {
            this.name = name;
            this.amnt = amnt;
        }
    }

    static void funcAdd(Product[][][] warehouse, String product, String quantity, String place) { // фукнция добавить товар
        int placement = Integer.parseInt(place.substring(1)); // убираем зону, перевод строки в интовое значение, адрес ячейки
        int amount = Integer.parseInt(quantity); // количество товара
        int i = placement / 100 - 1; // адрес стеллажа
        int j = placement / 10 % 10 - 1; // адрес секции
        int k = placement % 10 - 1; // адрес полки
        if (i >= 0 && i < 10 && j >= 0 && j < 7 && k >= 0 && k < 4) { // проверка на правильность адреса
            if ((warehouse[i][j][k].amnt + amount) <= 10) { // проверка на количества товара на полке
                if (warehouse[i][j][k].name.equals("0") || warehouse[i][j][k].name.equals(product)) { // если полка пуста или там лежит тот же товар
                    warehouse[i][j][k].name = product;
                    warehouse[i][j][k].amnt += amount;
                }
                else {
                    System.out.println("В ячейке уже лежит другой товар: " + warehouse[i][j][k].name);
                }
            }
            else {
                System.out.println("Ячейка переполнена.");
            }
        }
        else {
            System.out.println("Такой ячейки не существует.");
        }
    }

    static void funcRemove(Product[][][] warehouse, String product, String quantity, String place) { // функция удалить товар
        int placement = Integer.parseInt(place.substring(1)); // убираем зону, перевод строки в интовое значение, адрес ячейки
        int amount = Integer.parseInt(quantity); // количество товара
        int i = placement / 100 - 1; // адрес стеллажа
        int j = placement / 10 % 10 - 1; // адрес секции
        int k = placement % 10 - 1; // адрес полки
        if (i >= 0 && i < 10 && j >= 0 && j < 7 && k >= 0 && k < 4) { // проверка на правильность адреса
            if ((warehouse[i][j][k].amnt - amount) >= 0) { // проверка на количество товара на полке
                if (warehouse[i][j][k].name.equals(product)) { // проверка: именно этот товар находится на полке
                    warehouse[i][j][k].amnt -= amount;
                    if (warehouse[i][j][k].amnt == 0) { // если количество = 0, обнуляем название товара
                        warehouse[i][j][k].name = "0";
                    }
                }
                else {
                    System.out.println("В ячейке лежит другой товар: " + warehouse[i][j][k].name);
                }
            }
            else {
                System.out.println("В ячейке слишком мало товара.");
            }
        }
        else {
            System.out.println("Такой ячейки не существует.");
        }
    }

    static void funcInfo(Product[][][] warehouse) { // функция информация о складе
        double sum = 0.0; // количество всех товаров
        double racks = 0.0; // количество товаров в каждом стеллаже
        for (int i = 0; i < 10; i++) {
            racks = 0.0;
            for (int j = 0; j < 7; j++) {
                for (int k = 0; k < 4; k++) {
                    sum += warehouse[i][j][k].amnt;
                    racks += warehouse[i][j][k].amnt;
                }
            }
            System.out.println((i + 1) + " стеллаж заполнен на " + String.format("%.2f", racks / 280 * 100) + "%.");
        }
        System.out.println("Склад заполнен на " + String.format("%.2f", sum / 2800 * 100) + "%.");
        for (int i = 0; i < 10; i++) { // вывод заполненных ячеек
            for (int j = 0; j < 7; j++) {
                for (int k = 0; k < 4; k++) {
                    if (warehouse[i][j][k].amnt != 0) {
                        System.out.println("Ячейка а" + (i + 1) + (j + 1) + (k + 1) + ": " + warehouse[i][j][k].name + " " + warehouse[i][j][k].amnt);
                    }
                }
            }
        }
        System.out.print("Адреса пустых ячеек: ");
        for (int i = 0; i < 10; i++) { // вывод пустых ячеек
            for (int j = 0; j < 7; j++) {
                for (int k = 0; k < 4; k++) {
                    if (warehouse[i][j][k].amnt == 0) {
                        System.out.print("а" + (i + 1) + (j + 1) + (k + 1) + " ");
                    }
                }
            }
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Product[][][] warehouse = new Product[10][7][4];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 7; j++) {
                for (int k = 0; k < 4; k++) {
                    warehouse[i][j][k] = new Product("0", 0); // заполнение структуры нулями
                }
            }
        }
        while (true) {
            System.out.println("Введите комманду (add, remove, info, exit): ");
            String[] command = in.nextLine().split(" "); // команда
            if (command[0].equals("exit")) {
                break;
            }
            else if (command[0].equals("add")) {
                funcAdd(warehouse, command[1], command[2], command[3]);
            }
            else if (command[0].equals("remove")) {
                funcRemove(warehouse, command[1], command[2], command[3]);
            }
            else if (command[0].equals("info")) {
                funcInfo(warehouse);
            }
        }
    }
}

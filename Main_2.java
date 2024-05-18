import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main_2 {
    static class Pair {
        int time;
        List<String> talons;
        Pair(int time) {
            this.time = time;
            this.talons = new ArrayList<>();
        }
    }

    static String makeTalon(int i) { // функция для создания талона
        return "T" + i;
    }

    static void funcEnqueue(List<Pair> queue, String t, int N, String talon) { // функция заполнения очереди
        int time = Integer.parseInt(t); // перевод из строки в инт
        int k = 0;
        for (int i = 0; i < N; i++) { // проверка на переполнение очереди
            if ((queue.get(i).time + time) > 10) { // предел - 10 минут
                k++;
            }
        }
        if (k == N) {
            System.out.println(">>> В очереди больше нет мест.");
        }
        for (int i = 0; i < N; i++) {
            if ((queue.get(i).time + time) <= 10) {
                queue.get(i).talons.add(talon); // заполнение талонами
                queue.get(i).time += time;
                break;
            }
        }
    }

    static void funcDistribute(List<Pair> queue) { // функция для вывода распределения
        int it = 1; // итератор для номера окна
        for (Pair pair : queue) { // перебор пар
            System.out.print(">>> Окно " + it + " (" + pair.time + " минут): ");
            it++;
            for (String str : pair.talons) { // перебор талонов в окне
                System.out.print(str + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print(">>> Введите кол-во окон\n<<< ");
        int N = in.nextInt(); // количество окон
        in.nextLine(); // удаление символа новой строки из потока для дальнейшего ввода
        int it = (int) (Math.random() * 801) + 100; // случайное значение номера для талона
        List<Pair> queue = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            queue.add(new Pair(0)); // заполнение 0
        }
        while (true) {
            System.out.print("<<< ");
            String[] command = in.nextLine().split(" "); // ввод команды
            if (command[0].equals("exit")) {
                break;
            }
            else if (command[0].equals("enqueue")) {
                String talon = makeTalon(it); // получение талона
                it++; // изменение номера талона на последующий
                System.out.println(">>> " + talon);
                funcEnqueue(queue, command[1], N, talon);
            }
            else if (command[0].equals("distribute")) {
                funcDistribute(queue);
            }
            else { // проверка на корректность введённой команды
                System.out.println(">>> Некорректная команда.");
            }
        }
    }
}
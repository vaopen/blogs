package view;

import java.util.Scanner;
import model.Model;

public class View {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("��ӭ����������ĵ�S_2048");
		System.out.println("��Ϸ��ʼ");
		Model model = new Model();
		model.newgame();
		System.out.println(model.toString());
		String s = "";
		while(s != "exit") {
			System.out.println("�����뷽��");
			s = in.nextLine();
			model.move(s);
			model.increase();
			System.out.println(model.toString());
		}
		in.close();
		

	}

}

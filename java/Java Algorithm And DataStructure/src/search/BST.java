package search;

class Node<T> {
	private T value;

	public T getValue() {
		return value;
	}

	public void setValue(T value) {
		this.value = value;
	}

	public Node<T> getL_child() {
		return l_child;
	}

	public void setL_child(Node<T> l_child) {
		this.l_child = l_child;
	}

	public Node<T> getR_child() {
		return r_child;
	}

	public void setR_child(Node<T> r_child) {
		this.r_child = r_child;
	}

	private Node<T> l_child;
	private Node<T> r_child;

	public Node() {

	}

	public Node(T t) {
		value = t;
	}

}

// a test Object
class NodeValue implements Comparable<NodeValue> {

	private int x;
	private int y;

	public int getX() {
		return x;
	}

	public int getY() {
		return y;
	}

	public NodeValue() {
	}

	public NodeValue(int x, int y) {
		this.x = x;
		this.y = y;
	}

	@Override
	public String toString() {
		return "NodeValue [x=" + x + ", y=" + y + "]";
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see java.lang.Comparable#compareTo(java.lang.Object)
	 */
	@Override
	public int compareTo(NodeValue o) {
		// TODO Auto-generated method stub
		if (this.x != o.getX()) {
			return this.x - o.getX();
		} else {
			return this.y - o.getY();
		}
	}
}

public class BST {

	// test main method
	public static void main(String[] args) {
		int[] array = { 19, 12, 3, 22, 6, 7, 21, 11, 43 };
		Node<Integer> root = new Node<Integer>(array[0]);
		for (int i = 1; i < array.length; i++) {
			binaryInsert(root, array[i]);
		}

		// look this binary tree
		inOrderTraverse(root);

		if (binarySerach(root, 12)) {
			System.out.println("�������д��ڴ�Ԫ��");
		} else {
			System.out.println("�������в����ڸ�Ԫ��");
		}
		System.out.println("------------------------");
		NodeValue[] array1 = { new NodeValue(1, 2), new NodeValue(2, 2),
				new NodeValue(3, 4), new NodeValue(3, 5), new NodeValue(4, 3), };
		Node<NodeValue> root1 = new Node<NodeValue>(array1[0]);
		for (int i = 1; i < array1.length; i++) {
			binaryInsert(root1, array1[i]);
		}

		// look this binary tree
		inOrderTraverse(root1);

		if (binarySerach(root1, new NodeValue(1, 2))) {
			System.out.println("�������д��ڴ�Ԫ��");
		} else {
			System.out.println("�������в����ڸ�Ԫ��");
		}
	}

	// �����������������
	// using fanxing hanshu
	public static <T extends Comparable<T>> void binaryInsert(Node<T> root,
			T key) {
		if (root == null) {
			return;
		}
		T value = root.getValue();
		if (key.compareTo(value) < 0) {
			if (root.getL_child() == null) {
				Node<T> r = new Node<T>(key);
				root.setL_child(r);
			} else {
				binaryInsert(root.getL_child(), key);
			}
		} else {
			if (root.getR_child() == null) {
				Node<T> r = new Node<T>(key);
				root.setR_child(r);
			} else {
				binaryInsert(root.getR_child(), key);
			}
		}
	}

	// ����������
	public static <T extends Comparable<T>> boolean binarySerach(Node<T> root,
			T key) {
		if (root == null) {
			// throw new NullPointerException();
			return false;
		} else if (root.getValue().compareTo(key) == 0) {
			return true;
		} else if (root.getValue().compareTo(key) < 0) {
			return binarySerach(root.getR_child(), key);
		} else {
			return binarySerach(root.getL_child(), key);
		}
	}

	// ɾ��ĳ���ڵ�
	public static <T extends Comparable<T>> boolean delete(Node<T> root, T key) {
		if (root == null) {
			return false;
		}
		if (root.getValue().compareTo(key) == 0) {
			if (root.getR_child() == null) {
				root = root.getL_child();
				return true;
			} else if (root.getL_child() == null) {
				root = root.getR_child();
				return true;
			} else {
				root = root.getR_child();
				return true;
			}
		} else if (root.getValue().compareTo(key) > 0) {
			return delete(root.getL_child(), key);
		} else {
			return delete(root.getR_child(), key);
		}
	}

	// non modify
	private static Node<Integer> getSuccessor(Node<Integer> delNode) {
		// ��̽ڵ�ĸ��ڵ�
		Node<Integer> successorParent = delNode;
		// ��̽ڵ�
		Node<Integer> successor = delNode.getR_child();
		// �жϺ�̽ڵ��Ƿ�������
		Node<Integer> current = successor.getL_child();
		while (current != null) {
			successorParent = successor;
			successor = current;
			current = current.getL_child();
		}
		// ���ú�̽ڵ������ڰ������ӽڵ���ҽڵ���ӽڵ�
		if (successor != delNode.getR_child()) {
			successorParent.setL_child(successor.getR_child());
			// ���ӱ�ɾ���ڵ���Һ���
			successor.setR_child(delNode.getR_child());
		}
		return successor;
	}

	// �������,�ݹ�ʵ��
	public static <T> void inOrderTraverse(Node<T> root) {
		if (root == null) {
			return;
		}
		inOrderTraverse(root.getL_child());
		System.out.print(root.getValue() + "  ");
		inOrderTraverse(root.getR_child());
	}
}

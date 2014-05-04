package graph;

import java.util.List;

/**
 * @author Administrator
 * @description Graph interface.
 * @param <V>
 */
public interface Graph<V> {
	// ����ͼ�ж���ĸ���
	public int getSize();

	// ����ͼ�еĶ���
	public List<V> getVertices();

	// ����ָ�������±�Ķ������
	public V getVertex(int index);

	//����ָ��������±�
	public int gerIndex(V v);

	//����ָ�������±�Ķ�����ھ�
	public List<Integer> getNeighbors(int index);
	
	//����ָ���±�Ķ���Ķ�
	public int getDegree(int index);

	//�����ڽӾ���
	public int[][] getAdjacencyMatrix();

	//��ӡ�ڽӾ���
	public void printAdjacencyMatrix();

	//��ӡ��
	public void printEdges();

	//��ȡһ���������������
	public AbstractGraph<V>.Tree dfs(int index);

	//��ȡһ���������������
	public AbstractGraph<V>.Tree bfs(int index);
}

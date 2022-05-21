#include<iostream>

using namespace std;
<<<<<<< HEAD

class Board{
private:
	int data[3][3];
public:
	int step; // 步数
	int cost; // 每个格子
	Board(){}
    Board(const int a[3][3]){
        step = 0;
        cost = 0;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				data[i][j] = a[i][j];
=======
class Node{
public:
	int data[3][3];
	int step;
	int cost;
	int dir;
	Node* parent;
	Node(){}
	Node(int a[3][3]){
		for (int i=0; i<3; i++)
			for (int j=0; j<3; j++)
				data[i][j]=a[i][j];
>>>>>>> 1e561e20c4ad75bc4b72b4cec5bc6c25141dcd8e
		cost = calc_cost();
		step = 0;
		parent = NULL;
	}
<<<<<<< HEAD
/* 每个棋子的最终位置*/
    int* map_rc(int i){
		int* a = new int[2];
		if (i == 1){ a[0] = 0; a[1] = 0; }
		else if (i == 2){ a[0] = 0; a[1] =1; }
		else if (i == 3){ a[0] = 0; a[1] =2; }
		else if (i == 4){ a[0] = 1; a[1] =0; }
		else if (i == 5){ a[0] = 1; a[1] =1; }
		else if (i == 6){ a[0] = 1; a[1] =2; }
		else if (i == 7){ a[0] = 2; a[1] =0; }
		else if (i == 8){ a[0] = 2; a[1] =1; }
=======
	int* map_rc(int i){
		int a[2]; 
		if (i==1){ a[0]=0; a[1]=0; }
		else if (i==2){ a[0]=0; a[1]=1; }
		else if (i==3){ a[0]=0; a[1]=2; }
		else if (i==4){ a[0]=1; a[1]=0; }
		else if (i==5){ a[0]=1; a[1]=1; }
		else if (i==6){ a[0]=1; a[1]=2; }
		else if (i==7){ a[0]=2; a[1]=0; }
		else if (i==8){ a[0]=2; a[1]=1; }
>>>>>>> 1e561e20c4ad75bc4b72b4cec5bc6c25141dcd8e
		/*else if (i==0){ a[0]=2; a[1]=2; }*/
		return a;
	}

	int calc_cost(){
		cost = 0;
		for (int i=0; i<3; i++)
			for (int j=0; j<3; j++){
				if (data[i][j]!=0){
					int p = map_rc(data[i][j])[0];
					int q = map_rc(data[i][j])[1];
					cost += abs(p-i) + abs(q-j);
				}
			}
		return cost;
	}
	bool equals(const Board& node){
		for (int i=0; i<3; i++)
			for (int j=0; j<3; j++)
				if (data[i][j]!=node.data[i][j])
					return false;
		return true;
	}
	bool is_solved(){
		int k=1;
		for (int i=0; i<3; i++)
			for (int j=0; j<3; j++){
				if (data[i][j]!=k++)
					return false;
				if (k==9)
					k = 0;
			}
		return true;
	}
	void move(int dir){
		//east 0, south 1, west 2, north 3
		this->dir = dir;
		for (int i=0; i<3; i++)
			for (int j=0; j<3; j++)
				if (dir == 0){
					if (data[i][j]==0 && j!=0){
<<<<<<< HEAD
                        data[i][j] = data[i][j-1];
                        data[i][j-1] = 0;
=======
						data[i][j] = data[i][j-1];
						data[i][j-1] = 0;
						cost = calc_cost();
						step += 1;
						return;
>>>>>>> 1e561e20c4ad75bc4b72b4cec5bc6c25141dcd8e
					}
				}
				else if (dir==1){
					if (data[i][j]==0 && i!=0){
						data[i][j] = data[i-1][j];
						data[i-1][j] = 0;
<<<<<<< HEAD
=======
						cost = calc_cost();
						step += 1;
>>>>>>> 1e561e20c4ad75bc4b72b4cec5bc6c25141dcd8e
						return;
					}
				}
				else if (dir==2){
					if (data[i][j]==0 && j!=2){
						data[i][j] = data[i][j+1];
						data[i][j+1] = 0;
<<<<<<< HEAD
=======
						cost = calc_cost();
						step += 1;
>>>>>>> 1e561e20c4ad75bc4b72b4cec5bc6c25141dcd8e
						return;
					}
				}
				else{
					if (data[i][j]==0 && i!=2){
						data[i][j] = data[i+1][j];
						data[i+1][j] = 0;
<<<<<<< HEAD
=======
						cost = calc_cost();
						step += 1;
>>>>>>> 1e561e20c4ad75bc4b72b4cec5bc6c25141dcd8e
						return;
					}
				}
	}
	void output(){
		cout<<endl;
		for (int i=0; i<3; i++){
			for (int j=0; j<3; j++)
				if (data[i][j]==0)
					cout<<"  ";
				else
					cout<<data[i][j]<<" ";
			cout<<endl;
		}
<<<<<<< HEAD
        cout<<'cost='<<cost<<endl;
        cout<<'step='<<step<<endl;
	}
};

class Boards{
	Board data[1000];
	int n;
public:
	Boards():n(0){}
	void append(const Board& node){
		data[n++] = node;
	}
    void sort_by_cost() {

    }
=======
		cout<<"------  cost="<<cost<<", step="<<step<<endl;
		cout<<endl;
	}
};

class Nodes{
public:
	Node data[1000];
	int n;
	Nodes():n(0){}
	void sort_by_cost(){
		for (int i=0;i<n-1;i++)
			for (int j=i+1;j<n;j++)
				if (data[i].cost+data[i].step>
					data[j].cost+data[j].step){
					Node t;
					t = data[j];
					data[j] = data[i];
					data[i] = t;
				}
	}
	void append(Node node){
		data[n++] = node;
	}
	Node pop(){
		Node temp = data[0];
		for (int i=0;i<n-1;i++)
			data[i] = data[i+1];
		n--;
		return temp;
	}
>>>>>>> 1e561e20c4ad75bc4b72b4cec5bc6c25141dcd8e
	void output(){
		for (int i=0;i<n;i++)
			data[i].output();
	}
	bool contains(const Board& node){
		for (int i=0;i<n;i++)
			if (data[i].equals(node))
				return true;
		return false;
	}
};

<<<<<<< HEAD
int main(){
	int a[3][3] = {{1,2,3},{0,4,6},{7,5,8}};
	int b[3][3] = {{1,2,3},{4,0,6},{7,5,8}};
	int c[3][3] = {{7,1,8},{6,3,5},{0,2,4}};
	Board node(a);
	Board node2(b);
	Board node3(c);
	/*Boards nodes;。
	nodes.append(node);
	nodes.append(node2);
	nodes.output();
	cout<<nodes.contains(node3);*/
	node3.output();
	cout<<node3.cost;
=======
class Game{
public:
	Node data;
	Nodes nodes_visited;
	Nodes nodes_to_visit;
	Game(Node node):data(node){}
	bool solve(){
		nodes_to_visit.append(data);
		while (nodes_to_visit.n>0){
			Node node = nodes_to_visit.pop();
			nodes_visited.append(node);
			if (node.is_solved()){
				cout<<"solved."<<endl;
				int t[100];
				int k = 0;
				Node* p = &node;
				while (p->parent!=NULL){
					//cout<<p->dir;
					t[k++] = p->dir;
					p = p->parent;
				}
				for (int i=k-1; i>=0; i--)
					if (t[i]==0)
						cout<<"right ";
					else if (t[i]==1)
						cout<<"down ";
					else if (t[i]==2)
						cout<<"left ";
					else 
						cout<<"up ";
				return true;
			}
			Node node0 = node;
			for (int i=0; i<4; i++){
				node.move(i);
				if (!nodes_visited.contains(node)){
					node.parent = &nodes_visited.data[nodes_visited.n-1];
					nodes_to_visit.append(node);
				}
				node = node0;
			}
			nodes_to_visit.sort_by_cost();
			//nodes_to_visit.output();
			///return false;
		}
		cout<<"no solution."<<endl;
		return false;
	}
	void output(){
		data.output();
		cout<<"----------------"<<endl;
	}
};

void main(){
	int a[3][3] = {{1,2,3},{7,4,6},{0,5,8}};
	Node node(a);
	Game game(node);
	game.output();
	game.solve();
>>>>>>> 1e561e20c4ad75bc4b72b4cec5bc6c25141dcd8e
	getchar();
}
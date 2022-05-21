#include<iostream>

using namespace std;

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
		cost = calc_cost();
	}
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
	bool solved(){
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
		for (int i=0; i<3; i++)
			for (int j=0; j<3; j++)
				if (dir == 0){
					if (data[i][j]==0 && j!=0){
                        data[i][j] = data[i][j-1];
                        data[i][j-1] = 0;
					}
				}
				else if (dir==1){
					if (data[i][j]==0 && i!=0){
						data[i][j] = data[i-1][j];
						data[i-1][j] = 0;
						return;
					}
				}
				else if (dir==2){
					if (data[i][j]==0 && j!=2){
						data[i][j] = data[i][j+1];
						data[i][j+1] = 0;
						return;
					}
				}
				else{
					if (data[i][j]==0 && i!=2){
						data[i][j] = data[i+1][j];
						data[i+1][j] = 0;
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
	getchar();
}
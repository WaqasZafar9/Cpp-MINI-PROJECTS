#include<iostream>
#include<random>
#include<ctime>
using namespace std;
class game
{
	private:
		int num ;
		double score ;
	public:
		game()
		{
			num = 0;
			score = 0;
		}
		game(int n,int s)
		{
          n = num;
          s = score;
		}
		void display(){
			cout<<"Guess :"<<num<<endl;
			cout<<"Score :"<<score<<endl;
		}
		void guessGame()
		{
		int r = 1 + rand() % 6;
		for(int r = 1; r<=10; r++){
			cout<<"turn # "<<r<<endl;
			cout<<"Enter Your Guess :";
			cin >> num;
			cout<<"Actuall number is : "<<r<<endl;;
			if(num == r ){
				score++;
				cout << "Score :" << score << endl;
			}
			else if(num != r){
				score--;
				cout << "Score :" << score << endl;
		    }
		   // cout<<score<<endl;
		    cout<<"---------------------------"<<endl;
		}
			if(score>=3){
			cout<<"YOU WON"<<endl;
			}
			else{
				cout<<"YOU LOSE"<<endl;
			}
		}		
		
};
int main(){
	game* g1 = new game();
	g1->display();
	srand(time(0));
	g1->guessGame();
}

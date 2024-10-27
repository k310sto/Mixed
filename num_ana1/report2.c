#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int liter_code(char n){		//添え字を文字コードに変換する関数
	switch(n){
	case 52 :
		return 39;
	case 53 :
		return 44;
	case 54 :
		return 46;
	default :
		if( n <= 25 ) 
			return (n + 65);
		else if( n <= 51 )
			return (n + 71);
		else 
			return 0;
	}
}


int main(){

	char filename[] = "output.txt";
 
	char letr;

	struct statis{
		char code;				//文字識別用
		unsigned int num;			//出現個数用
	};
	struct statis moji[55];

	for(int j = 0; j < 55; j++){			//初期化
		moji[j].num = 0;
	}

	FILE *ip = fopen(filename, "r");
	while( (letr = fgetc(ip)) != EOF ){
		for( int i = 0; i < 55; i++ ){		//"z"が文字コード122
			moji[i].code = liter_code(i);	//今から調べる文字のコードを格納
			if( letr == moji[i].code ){
				moji[i].num++;
				break;
			}
		}
	}
	fclose(ip);


	//---バブルソート---//
	double tmp;
	for(int i = 0; i < 54; i++ ){
		for(int j = 0; j < 54; j++){
			if(moji[j].num < moji[j+1].num){
				tmp = moji[j].num;
				moji[j].num = moji[j+1].num;
				moji[j+1].num = tmp;
				tmp = moji[j].code;
				moji[j].code = moji[j+1].code;
				moji[j+1].code = tmp;
			}
		}
	}
	for(int i = 0; i < 55; i++){
		if(moji[i].num > 0)
			printf("<%c> : %d \n",moji[i].code, moji[i].num);

	}
return 0;
}

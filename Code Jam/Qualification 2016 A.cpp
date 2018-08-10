#include<stdio.h>

int main(){
	int t, n, temp, tt = 1, i;
	int vec[10] = {0};
	scanf("%d", &t);
	
	while(t--){
		for(int i = 0; i < 10; i++) vec[i] = 0;
		
		scanf("%d", &n);

		for(i = 1; i <= 100; i++){
			for(temp = i * n; temp > 0; temp /= 10) vec[temp % 10] = 1;
			if(vec[0] && vec[1] && vec[2] && vec[3] && vec[4] && vec[5] && vec[6] && vec[7] && vec[8] && vec[9]) {printf("Case #%d: %d\n", tt, i * n); break;}
		}


		if(i >= 100) printf("Case #%d: INSOMNIA\n", tt);
		tt++;
	}
	
}
#include<stdio.h>
#include<string.h>
struct Dish{
	int id;
	char name[100];
	double price;
};
int main(){
	int luachon;
	struct Dish Dishes[100]={
		{1,"sashimi",1000	},
		{2,"nemchua",45000	},
		{3,"nemran",3000	},
		{4,"nemthinh",4000	},
		{5,"nemransotcachua",7000	},
	};
	int n=5;
	while(1){
		printf("\n----------menu----------\n");
		printf("1.in ra cac phan tu co trong menu mon an\n");
		printf("2.them mot phan tu vao vi tri cuoi\n");
		printf("3.sua mot phan tu o vi tri chi dinh\n");
		printf("4.xoa mot phan tu o vi tri chi dinh\n");
		printf("5.xap xep cac mon an theo gia tien\n");
		printf("6.tim kiem cac mon an theo ten\n");
		printf("7.thoat\n");
		printf("moi xep chon: ");
		scanf("%d",&luachon);
		fflush(stdin);
		switch(luachon){
			case 1:{
				for(int i=0;i<n;i++){
					printf("%d .%s: %.lf\n",Dishes[i].id,Dishes[i].name,Dishes[i].price);
				}
				break;
			}
			case 2:{
				struct Dish neww;
				neww.id=n+1;
				printf("nhap vao mon moi: ");
				fgets(neww.name,sizeof(neww.name),stdin);
				neww.name[strlen(neww.name)-1]='\0';
				printf("nhap vao gia tien mon moi: ");
				scanf("%lf",&neww.price);
				fflush(stdin);
				Dishes[n]=neww;
				n++;
				printf("Dishes sau khi thay doi la: \n");
				for(int i=0;i<n;i++){
					printf("%d .%s: %lf\n",Dishes[i].id,Dishes[i].name,Dishes[i].price);
				}
				break;
			}
			case 3:{
				int updates;
				int search=-1;
				printf("nhap vao id muon sua: ");
				scanf("%d",&updates);
				fflush(stdin);
				for(int i=0;i<n;i++){
					if(updates==Dishes[i].id){
						printf("nhap vao mon sua: ");
						fgets(Dishes[i].name,sizeof(Dishes[i].name),stdin);
						Dishes[i].name[strlen(Dishes[i].name)-1]='\0';
						printf("nhap vao gia tien muon sua: ");
						scanf("%lf",&Dishes[i].price);
						fflush(stdin);
						search=i;
					}
				}
				if(search==-1){
					printf("khong co vi tri nao hop le de sua!!");
				}
				printf("Dishes sau khi thay doi la: \n");
				for(int i=0;i<n;i++){
					printf("%d .%s: %lf\n",Dishes[i].id,Dishes[i].name,Dishes[i].price);
				}
				break;
			}
			case 4:{
				int updates;
				printf("nhap vao id muon xoa: ");
				scanf("%d",&updates);
				fflush(stdin);
				for (int i = updates-1; i < n - 1; i++) {
                            Dishes[i] = Dishes[i + 1];
                        }
                        n--;
                printf("dish sau khi xoa la: \n");
                for(int i=0;i<n;i++){
					printf("%d .%s: %lf\n",Dishes[i].id,Dishes[i].name,Dishes[i].price);
				}
				break;
			}
			case 5:{
				for(int i=1;i<n;i++){
	        	int key=Dishes[i].price;
	         	int j=i-1;
	        	while(j>=0&&key<Dishes[j].price){
	     		Dishes[j+1].price=Dishes[j].price;
	    		j--;
	        	}
	        	Dishes[j+1].price=key;
            	}
	            printf("dishes sau khi duoc xap xep giam dan la: \n");
                for(int i=0;i<n;i++){
					printf("%d .%s: %lf\n",Dishes[i].id,Dishes[i].name,Dishes[i].price);
				}
				break;
			}
			case 6:{
				char search[100];
				printf("nhap vao ten mon an muon tim kiem:");
			   	fgets(search,100,stdin);
			   	search[strlen(search)-1]='\0';
			   	int update=-1;
			   	for(int i=0;i<n;i++){
			   	
			   		if(strcmp(search, Dishes[i].name)==0){
					    update=i;
			   			printf("mon an co trong cac dishes va no co id la: %d",Dishes[i].id);
					   }
				   }
				   if(update==-1){
				   	printf("mon an muon tim khong co trong dishmenu!!");
				   }
				break;
			}
			case 7:{
				printf("ban da thoat menu!!");
				return 0;
			}
			default :{
				printf("lua chon cua sep khong hop le");
				break;
			}
		}
	}
	return 0;
}

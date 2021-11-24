#include<stdio.h>
#include<windows.h>
  int choice,nume,i,j,n=0;
  float num[25],add,max,numa;
  char name[25][50],cin[25][50],s[25],mid[25],min[25];
  void affichage(){
  	for(i=0; i<n; i++){                            //printing all users to choose which one to log in as
        printf("\t%d--nom:  %s",i+1, name[i]);
        printf("\t%d--CIN:  %s",i+1, cin[i]);
        printf("\t%d--montant:  %f\n",i+1, num[i]);
    }
  }
  void search(){
 		    printf("Donner cin de client: ");
	        scanf("%s", &s);
   //La recherche initailiser par zero
   i = 0;
   while (i < n && strcmp(s,cin[i])!=0) {
      i++;
   }
   if (strcmp(s,cin[i])==0) {
      printf("compte se trouve dans la position = %d", i + 1);
   } 
   else {
      printf("compte non trouve");
   }
 }
 void selection(){
		

//premier case	
	for ( i=0;i<n;i++){
//		comparer avec le premier case
		for ( j=i+1;j<n;j++){
			if (num[i]<num[j]){
//				permutation
 			max = num[i];
			num[i] = num[j];
			num[j] = max;
			//pour nom
        strcpy(min,name[i]);
		strcpy(name[i],name[j]);
		strcpy(name[j],min);			

//pour cin
		strcpy(mid,cin[i]);
		strcpy(cin[i],cin[j]);
		strcpy(cin[j],mid);
			}
		}
	}

}
void selection2(){
		

//premier case	
	for ( i=0;i<n;i++){
//		comparer avec le premier case
		for ( j=i+1;j<n;j++){
			if (num[i]>num[j]){
//				permutation
 			max = num[i];
			num[i] = num[j];
			num[j] = max;
//pour nom
        strcpy(min,name[i]);
		strcpy(name[i],name[j]);
		strcpy(name[j],min);			

//pour cin
		strcpy(mid,cin[i]);
		strcpy(cin[i],cin[j]);
		strcpy(cin[j],mid);
	
			}
		}
	}

}
void selection3(){
		
            printf("donner le montant: ");
			scanf("%f",&numa);
            for( i = 0;i<n;i++){
            if(num[i]>=numa ){
            printf("\t%d--nom:  %s",i+1, name[i]);
            printf("\t%d--CIN:  %s",i+1, cin[i]);
            printf("\t%d--montant:  %f\n",i+1, num[i]);	
             }
}
   }
   void selection4(){
		
            printf("donner le montant: ");
			scanf("%f",&numa);
            for( i = 0;i<n;i++){
            if(num[i]<=numa ){
            printf("\t%d--nom:  %s",i+1, name[i]);
            printf("\t%d--CIN:  %s",i+1, cin[i]);
            printf("\t%d--montant:  %f\n",i+1, num[i]);	
   }
}
}
 void menu(void)
{  
    system("cls");
    system("color 3");
    
    menu:
    
    printf("\n\n\t\t\tSYSTEME DE GESTION BANCAIRE DU COMPTE CLIENT");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BIENVENUE AU MENU PRINCIPAL \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Creer un compte\n\t\t2.creer plusieurs comptes\n\t\t3.autre operation \n\t\t4.affichage des comptes\n\t\t5.recherche par cin \n\t\t6.Fidelisation\n\t\t7.Quitter application\n\n\n\n\n\t\t Donner votre choix:");
    scanf("%d",&choice);
    if(choice==1){
    	for(i=n;i<n+1;i++){
    	printf("Donner votre nom: ");
    	scanf("%s",&name[i]);
    	printf("Donner votre cin: ");
    	scanf("%s",&cin[i]);
    	printf("Donner votre montant:  ");
    	scanf("%f",&num[i]);
    	printf("\t--nom:  %s",name[i]);
        printf("\t--CIN:  %s",cin[i]);
        printf("\t--montant:  %f\n",num[i]);
       }
       n=n+1;
    	goto menu;
	}
	else if(choice==2){
        printf("combien de compte tu veux faire : ");
    	scanf("%d",&nume);
//scan element 
    for ( i=n;i<nume+n;i++){
    	getc(stdin);
    	printf("\nDonner client %d nom : ",i+1);
    	gets(name[i]);
    	printf("\nDonner client %d CIN : ",i+1);
    	scanf("%s",&cin[i]);
    	printf("\nDonner client %d montant: ",i+1);
    	scanf("%f",&num[i]);
    	
    	}
    	n=n+nume;
    	affichage();  
    
    goto menu;
	}
	else if(choice==3){
		search();
		printf("\n1.Retrait \n2.Depot \nDonner votre choix:");
		scanf("%d",&choice);
		if (choice==1){
			printf("donner montant tu veux retrait: ");
			scanf("%f",&add);
			if(num[i]>add){
		        printf("%f est votre solde maitenant",num[i]=num[i]-add);
			}
			else{
				printf("montant tu veux retrait est Plus grand par votre solde");
			}
		    } 
		else if (choice==2){
			printf("donner montant tu veux depot: ");
			scanf("%f",&add);
		    printf("%f est votre solde maitenant",num[i]=num[i]+add);
		}
		
		goto menu;
	}
	    

	
	else if(choice==4){
	    affichage();
	    printf("1.Par Ordre Ascendant \n2.Par Ordre Descendant \n3.le plus grand par votre montant \n4.le plus petit par votre montant \nDonner votre choix:");
	    scanf("%d",&choice);
	    if(choice==1){
	    	selection();
	    	affichage();
		}
		else if(choice==2){
			selection2();
			affichage();
	    	
		}
		else if(choice==3){
			selection3();

		}
		else if (choice==4){
			selection4();
		}
		goto menu;
	}
	else if(choice==5){
     search();
     goto menu;
	}
	else if(choice==6){
      if(n<3){
      for( i =0;i<n;i++){
      printf("\n-Nous avons ajoute 1.3 dans %s le compte : %.2lf",cin[i],num[i]);
      num[i] += (num[i]*1.3)/100;
      printf("\nle montant maintenant est  %.2lf ",num[i]);
      }
     }
	 else{
	 selection();
     for(i=0;i<3;i++ ){
     printf("\n-Nous avons ajoute 1.3 dans %s le compte : %.2lf",cin[i],num[i]);
     num[i] += (num[i]*1.3)/100;
     printf("\nle montant maintenant est %.2lf ",num[i]);
     }
     }
     goto menu;
	}
	else if(choice==7){

	}
}
int main(){
    
   menu();

    return 0;
}

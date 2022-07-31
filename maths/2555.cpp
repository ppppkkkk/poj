
const double cw=4.19,ci=2.09,em=335;
int main()
{
	double mw,mi,tw,ti;
	while(1){
		scanf("%lf%lf%lf%lf",&mw,&mi,&tw,&ti);
		if(fabs(mw+mi)<1e-6)
			break;
		double Q;
		Q=mw*(ci*30+em+cw*tw)+mi*ci*(30+ti);
		double m=(mw+mi);
		if(m*ci*30>Q){
			double T=Q/m/ci-30;
			printf("%.1lf g of ice and 0.0 g of water at %.1lf C\n",m,T);
		}
		else if(m*(ci*30+em)<Q){
			double T=(Q-m*(ci*30+em))/m/cw;
			printf("0.0 g of ice and %.1lf g of water at %.1lf C\n",m,T);
		}
		else{
			Q-=m*ci*30;
			double x=Q/em;		
			printf("%.1lf g of ice and %.1lf g of water at 0.0 C\n",m-x,x);
		}
	}
	return 0;	
}

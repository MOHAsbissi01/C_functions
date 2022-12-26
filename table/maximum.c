

// recherche d'un maximum

int max_membre(famille TF[], int nF){
    int max=0;
    for (int i = 0; i < nF; ++i) {
        if(TF[i].nbr_fam>TF[max].nbr_fam){
            max=i;
        }
    }
    return max;
}
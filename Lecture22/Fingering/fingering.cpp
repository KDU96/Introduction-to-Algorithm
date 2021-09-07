#include "fingering.hpp"

bool Compare(const FingerAndCostMsg& A, const FingerAndCostMsg& B){
    return A.cost < B.cost;
}
Fingering::Fingering(const int& size)
:NoteSequenceSize(size)
{
    srand(time(NULL));
    for(int i=0; i<NoteSequenceSize; i++)
        NoteSequence.push_back(rand() % 5);
    findOptimalFingering(); 

}
Fingering::~Fingering()
{
    if(optimalFingering)
        delete[] optimalFingering;
    else
        cout << "Fingering is failed " << endl;
}
int Fingering::findOptimalFingering(){
    vector<FingerAndCostMsg> table[5];
    int sum[5];
    for(int i=0; i<5; i++)
        sum[i]  =   0;

    FingerAndCostMsg tmp;
    for(int i=0; i<5; i++){
        tmp.cost        = pow(StringFingeringCost[NoteSequence[0]][i], 2);
        tmp.fingerNum   =     i;
        table[i].push_back(tmp);
        for(int j=0; j<NoteSequenceSize; j++){
            tmp     =   costFunction(j, tmp.fingerNum);
            sum[i]  += tmp.cost;
            table[i].push_back(tmp);
        }
    }
    int least = 0;
    for(int i=1; i<5; i++)
        if(sum[least] > sum[i])
            least   =   i;
    optimalFingering    =   new FingerAndCostMsg[NoteSequenceSize];

    for(int i=0; i<NoteSequenceSize; i++)
        optimalFingering[i]     =   table[least].at(i);
    return sum[least];
}
FingerAndCostMsg Fingering::costFunction(int idex, int f){//find next node
    vector<FingerAndCostMsg> tbl;
    FingerAndCostMsg tmp;
    for(int i=0; i<5; i++){
        tmp.cost  =   pow(f - i, 2) + pow(StringFingeringCost[NoteSequence[idex + 1]][i], 2);
        tmp.fingerNum   =   i;
        tbl.push_back(tmp);
    }
    sort(tbl.begin(), tbl.end(), Compare);
    return tbl[0];
}
void Fingering::printFingering() const{
    for(int i=0; i<NoteSequenceSize; i++){
        cout << NoteSequence.at(i) << '\t';
        cout << "cost " << optimalFingering[i].cost << '\t' << "finger num : " << optimalFingering[i].fingerNum << endl;
    }
}

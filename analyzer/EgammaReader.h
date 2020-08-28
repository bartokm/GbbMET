
#ifndef EgammaScalingReader_h
#define NanoAODselector_h


#define MAP_MULTIPLIER 1000 // r9 is given to 3 digits sometimes


///////////////////////////////////////////////// SHARED FUNCTIONS

std::vector<std::string > split(const std::string s, const char delimiter=' '){

    std::stringstream ss;
    ss << s;

    std::vector<std::string > segments;
    std::string segment;
    while (std::getline(ss, segment, delimiter)){
        segments.push_back(segment);
    }
    return segments;
}


int quantize(const float x, const std::vector<int>vec){
    int i0 = 0;
    int i1 = vec.size()-1;

    if (x <  vec[i0]) return vec[i0];
    if (x >= vec[i1]) return vec[i1];

    while ((i1-i0)>1){
        int mid = (i1+i0)/2;
        if   (x >= vec[mid]) i0 = mid;
        else                 i1 = mid;
    }
    return vec[i0];
}


///////////////////////////////////////////////// SCALING

class EgammaScalingReader{

    private:
    //public:
        std::map< int, std::map< int, std::map< int,  std::map< int, std::vector<float> > > > > etaLow2r9Low2gain2runLow2values;

        std::vector<int>    _etaVector_low;
        std::vector<int>    _r9Vector_low;
        std::vector<int>    _gainVector;
        std::vector<int>    _runVector_low;

        std::string version;


    public:
        EgammaScalingReader();
        EgammaScalingReader(const std::string, const int, const std::string);
        void line_reader_v1(const std::string, std::set<int>&, std::set<int>&, std::set<int>&, std::set<int>& );
        void line_reader_v2(const std::string, std::set<int>&, std::set<int>&, std::set<int>&, std::set<int>& );


        std::vector< float > get_vals(const float, const float, const float, const float);


        float get_energyScale(const float, const float, const float, const float, const int, const int, const int);
        float get_energyScaleTotUnc_Gain12(const float, const float, const float, const float);
        float get_energyScaleErrStat(const float, const float, const float, const float);
        float get_energyScaleErrSyst(const float, const float, const float, const float);
        float get_energyScaleErrGain(const float, const float, const float, const float);
};



std::vector< float > EgammaScalingReader::get_vals(const float eta, const float r9, const float gain, const float run){

    // int rAbsEta = round(abs(eta)*MAP_MULTIPLIER);
    int iAbsEta = int(abs(eta)*MAP_MULTIPLIER);
    // int rR9 = round(r9*MAP_MULTIPLIER);
    int iR9 = int(r9*MAP_MULTIPLIER);

    int   k0 = quantize(iAbsEta, _etaVector_low);
    int   k1 = quantize(iR9, _r9Vector_low);
    int   k2 = quantize(gain, _gainVector);
    int   k3 = quantize(run, _runVector_low);

    // std::cout<<k0<<" "<<k1<<" "<<k2<<" "<<k3<<std::endl;
    // for (auto x : _etaVector_low) cout<<x<<" ";
    // cout<<endl;
    // for (auto x : _r9Vector_low) cout<<x<<" ";
    // cout<<endl;
    // for (auto x : _gainVector) cout<<x<<" ";
    // cout<<endl;

    // // for (auto x : etaLow2r9Low2gain2runLow2values.at(k0)) cout<<x.first<<" ";

    // auto x1 = etaLow2r9Low2gain2runLow2values.at(k0);
    // cout<<"OK1"<<endl;
    // auto x2 = etaLow2r9Low2gain2runLow2values.at(k0).at(k1);
    // cout<<"OK2"<<endl;
    // auto x3 = etaLow2r9Low2gain2runLow2values.at(k0).at(k1).at(k2);
    // cout<<"OK3"<<endl;
    // auto x4 = etaLow2r9Low2gain2runLow2values.at(k0).at(k1).at(k2).at(k3);
    // cout<<"OK4"<<endl;

    return etaLow2r9Low2gain2runLow2values.at(k0).at(k1).at(k2).at(k3);
}

float EgammaScalingReader::get_energyScale(const float eta, const float r9, const float gain, const float run, const int signErrStat=0, const int signErrSyst=0, const int signErrGain=0){

    int signErrStat_ = signErrStat;
    if (signErrStat==2){
        signErrStat_ = -1;
    }
    int signErrSyst_ = signErrSyst;
    if (signErrSyst==2){
        signErrSyst_ = -1;
    }
    int signErrGain_ = signErrGain;
    if (signErrGain==2){
        signErrGain_ = -1;
    }

    std::vector< float > temp = get_vals( eta, r9, gain, run);

    return temp[0] + signErrStat_ * temp[2] + signErrSyst_ * temp[3] + signErrGain_ * temp[4]; 
}

float EgammaScalingReader::get_energyScaleTotUnc_Gain12(const float eta, const float r9, const float gain, const float run){

    return get_vals( eta, r9, gain, run)[1];
}

float EgammaScalingReader::get_energyScaleErrStat(const float eta, const float r9, const float gain, const float run){

    return get_vals( eta, r9, gain, run)[2];
}

float EgammaScalingReader::get_energyScaleErrSyst(const float eta, const float r9, const float gain, const float run){

    return get_vals( eta, r9, gain, run)[3];
}

float EgammaScalingReader::get_energyScaleErrGain(const float eta, const float r9, const float gain, const float run){

    return get_vals( eta, r9, gain, run)[4];
}


void EgammaScalingReader::line_reader_v1(const std::string s, std::set<int>& etaSet_low, std::set<int>& r9Set_low, std::set<int>& gainSet, std::set<int>&runSet_low){

    std::stringstream ss;
    ss<<s;

    // read first column
    std::string etaR9GainName;
    ss>>etaR9GainName;

    std::vector<std::string > segments = split(etaR9GainName, '-');

    // eta
    std::vector<std::string > etaStringSegments = split(segments[0], '_');
    std::pair<int,int> etaRange = { int(MAP_MULTIPLIER*stof(etaStringSegments[1])), int(MAP_MULTIPLIER*stof(etaStringSegments[2]))};
    etaSet_low.insert(etaRange.first);

    // R9 
    std::pair<int,int> r9Range;
    if (segments[1]=="bad"){
        r9Range = {0,int(0.94*MAP_MULTIPLIER)};
        r9Set_low.insert(0);
    }
    else if (segments[1]=="gold")
    {
        r9Range = {int(0.94*MAP_MULTIPLIER), MAP_MULTIPLIER};
        r9Set_low.insert(int(0.94*MAP_MULTIPLIER));
    }
    else{
        std::vector<std::string > r9StringSegments = split(segments[1], '_');
        r9Range = {int(MAP_MULTIPLIER*stof(r9StringSegments[1])), int(MAP_MULTIPLIER*stof(r9StringSegments[2]))};
        r9Set_low.insert(r9Range.first);
    }

    //gain
    int gain = atoi((split(segments[2], '_')[1]).c_str());
    gainSet.insert(gain);

    // read second column
    std::string runNumberTxt;
    ss>>runNumberTxt;

    //....
    int runStart, runEnd;
    ss>>runStart;
    ss>>runEnd;
    runSet_low.insert(runStart);

    float x, y, energyScaleErrStat, energyScaleErrSyst,  energyScaleErrGain;
    ss>>x;
    ss>>y;
    ss>>energyScaleErrStat;
    ss>>energyScaleErrSyst;
    ss>>energyScaleErrGain;
    std::vector<float> values = {x, y, energyScaleErrStat, energyScaleErrSyst,  energyScaleErrGain};

    if (etaLow2r9Low2gain2runLow2values.count(etaRange.first)==0){
        etaLow2r9Low2gain2runLow2values[etaRange.first] = std::map< int, std::map< int,  std::map< int, std::vector<float> > > >();
    }
    if (etaLow2r9Low2gain2runLow2values[etaRange.first].count(r9Range.first)==0){
        etaLow2r9Low2gain2runLow2values[etaRange.first][r9Range.first] =  std::map< int,  std::map< int, std::vector<float> > >();
    }
    if (etaLow2r9Low2gain2runLow2values[etaRange.first][r9Range.first].count(gain)==0){
        etaLow2r9Low2gain2runLow2values[etaRange.first][r9Range.first][gain] = std::map< int, std::vector<float> >();
    }
    etaLow2r9Low2gain2runLow2values[etaRange.first][r9Range.first][gain][runStart] = values;
}

void EgammaScalingReader::line_reader_v2(const std::string s, std::set<int>& etaSet_low, std::set<int>& r9Set_low, std::set<int>& gainSet, std::set<int>&runSet_low){

    std::stringstream ss;
    ss<<s;
    
    int runMin, runMax, gain;
    float etaMin_f, etaMax_f, r9Min_f, r9Max_f, etMin_f, etMax_f, energyScale, energyScaleErr;
    int etaMin, r9Min;
    
    ss >> runMin >> runMax >> etaMin_f >> etaMax_f >> r9Min_f >> r9Max_f >> etMin_f >> etMax_f >> gain >> energyScale >> energyScaleErr;

    etaMin = int(MAP_MULTIPLIER*etaMin_f);
    r9Min  = int(MAP_MULTIPLIER*r9Min_f);

    etaSet_low.insert(etaMin);
    r9Set_low.insert(r9Min);
    gainSet.insert(gain);
    runSet_low.insert(runMin);

    std::vector<float> values = {energyScale, energyScaleErr};
    

    if (etaLow2r9Low2gain2runLow2values.count(etaMin)==0){
        etaLow2r9Low2gain2runLow2values[etaMin] = std::map< int, std::map< int,  std::map< int, std::vector<float> > > >();
    }
    if (etaLow2r9Low2gain2runLow2values[etaMin].count(r9Min)==0){
        etaLow2r9Low2gain2runLow2values[etaMin][r9Min] =  std::map< int,  std::map< int, std::vector<float> > >();
    }
    if (etaLow2r9Low2gain2runLow2values[etaMin][r9Min].count(gain)==0){
        etaLow2r9Low2gain2runLow2values[etaMin][r9Min][gain] = std::map< int, std::vector<float> >();
    }
    etaLow2r9Low2gain2runLow2values[etaMin][r9Min][gain][runMin] = values;
}


EgammaScalingReader::EgammaScalingReader(){
}

EgammaScalingReader::EgammaScalingReader(const std::string pathTo_EgammaScaling_dat, const int year, const std::string version= "v1"){

    this->version = version;

    //needs input json formatted as each run is a new line
    //std::cout<<"Reading Egamma scaling "<<year<<" version "<<version<<std::endl;

    std::set<int> etaSet_low;
    std::set<int> r9Set_low;
    std::set<int> gainSet;
    std::set<int> runSet_low;
    
    std::ifstream datfile(pathTo_EgammaScaling_dat);

    if (datfile.is_open()) {
        std::string s;
        if (version == "v1"){
            while( std::getline(datfile, s) ) {
                line_reader_v1(s, etaSet_low, r9Set_low, gainSet, runSet_low);
            }
        }
        else
        {
            while( std::getline(datfile, s) ) {
                line_reader_v2(s, etaSet_low, r9Set_low, gainSet, runSet_low);
            }
        }
        datfile.close();
    }
    else
    {
        std::cout<<"ERROR: reading Egamma Scaling failed!"<<std::endl;
        std::cout<<pathTo_EgammaScaling_dat<<std::endl;
        exit(1);
    }

    std::vector<int> etaVector_low(etaSet_low.begin(), etaSet_low.end());
    std::vector<int> r9Vector_low(r9Set_low.begin(), r9Set_low.end());
    std::vector<int> gainVector(gainSet.begin(), gainSet.end());
    std::vector<int> runVector_low(runSet_low.begin(), runSet_low.end());

    sort(etaVector_low.begin(), etaVector_low.end()); 
    sort(r9Vector_low.begin(), r9Vector_low.end()); 
    sort(gainVector.begin(), gainVector.end()); 
    sort(runVector_low.begin(), runVector_low.end()); 

    _etaVector_low  = etaVector_low;
    _r9Vector_low   = r9Vector_low;
    _gainVector     = gainVector;
    _runVector_low  = runVector_low;


    // some r9 values are missing apparently, this needs to be fixed
    for (auto l1 : etaLow2r9Low2gain2runLow2values){
        for (unsigned int i=0; i<r9Vector_low.size(); i++) {
            if (l1.second.count(r9Vector_low[i])==0){
                etaLow2r9Low2gain2runLow2values[l1.first][r9Vector_low[i]]= etaLow2r9Low2gain2runLow2values[l1.first][r9Vector_low[i-1]];
            }
        }
    }
    
}

///////////////////////////////////////////////// SMEARING


class EgammaSmearingReader{

    private:
    //public:
        std::map< int, std::map< int, std::vector<float> > >  etaLow2r9Low2values;

        std::vector<int> _etaVector_low;
        std::vector<int> _r9Vector_low;

    public:
        EgammaSmearingReader();
        EgammaSmearingReader(const std::string, const int );
        std::vector< float > get_vals(const float, const float);

        float get_Semar(const float, const float, const float, const int, const int);        
};

std::vector< float > EgammaSmearingReader::get_vals(const float eta, const float r9){

    int   k0 = quantize(int(abs(eta)*MAP_MULTIPLIER), _etaVector_low);
    int   k1 = quantize(int(r9*MAP_MULTIPLIER), _r9Vector_low);

    return etaLow2r9Low2values.at(k0).at(k1);
}

float EgammaSmearingReader::get_Semar(const float eta, const float r9, const float et, const int nrSigmaRho=0, const int nrSigmaPhi=0){

    int nrSigmaRho_ = nrSigmaRho;
    if (nrSigmaRho == 2){
        nrSigmaRho_ = -1;
    }
    int nrSigmaPhi_ = nrSigmaPhi;
    if (nrSigmaPhi == 2){
        nrSigmaPhi_ = -1;
    }

    const std::vector< float > temp = get_vals(eta, r9);

    const float eMean_  = temp[0];

    const float rho_    = temp[2];
    const float rhoErr_ = temp[3];

    const float phi_    = temp[4];
    const float phiErr_ = temp[5];

    const float rhoVal = rho_ + rhoErr_ * nrSigmaRho_;
    const float phiVal = phi_ + phiErr_ * nrSigmaPhi_;
    const float constTerm = rhoVal * std::sin(phiVal);
    const float alpha = rhoVal * eMean_ * std::cos(phiVal);
    return std::sqrt(constTerm * constTerm + alpha * alpha / et);
}

EgammaSmearingReader::EgammaSmearingReader(){
}

EgammaSmearingReader::EgammaSmearingReader(const std::string pathTo_EgammaSmearing_dat, const int year){
    //needs input json formatted as each run is a new line
    //std::cout<<"Reading Egamma smearing"<<std::endl;

    std::set<int> etaSet_low;
    std::set<int> r9Set_low;
    
    std::ifstream datfile(pathTo_EgammaSmearing_dat);

    if (datfile.is_open()) {
        std::string s;
        while( std::getline(datfile, s) ) {

            if (s.size()==0 || s[0] == '#') continue;

            std::stringstream ss;
            ss<<s;

            // read first column
            std::string etaR9GainName;
            ss>>etaR9GainName;

            std::vector<std::string > segments = split(etaR9GainName, '-');

            // eta
            std::vector<std::string > etaStringSegments = split(segments[0], '_');
            std::pair<int,int> etaRange = { int(MAP_MULTIPLIER*stof(etaStringSegments[1])), int(MAP_MULTIPLIER*stof(etaStringSegments[2]))};
            etaSet_low.insert(etaRange.first);

            // R9 
            std::pair<int,int> r9Range;
            if (year==2016){
                r9Range = {0,MAP_MULTIPLIER};
                r9Set_low.insert(0);
            }
            else if (year==2017) {
                if (segments[1]=="lowR9"){
                    r9Range = {0,940};
                    r9Set_low.insert(0);
                }
                else
                {
                    r9Range = {int(0.94*MAP_MULTIPLIER), MAP_MULTIPLIER};
                    r9Set_low.insert(int(0.94*MAP_MULTIPLIER));
                }
            }
            else{
                std::vector<std::string > r9StringSegments = split(segments[1], '_');
                r9Range = {int(MAP_MULTIPLIER*stof(r9StringSegments[1])), int(MAP_MULTIPLIER*stof(r9StringSegments[2]))};
                r9Set_low.insert(r9Range.first);
            }


            float Emean, err_Emean, rho, err_rho, phi, err_phi;
            ss>>Emean;
            ss>>err_Emean;
            ss>>rho;
            ss>>err_rho;
            // ss>>phi;
            // ss>>err_phi;
            phi     = M_PI_2;
            err_phi = M_PI_2;
            
            std::vector<float> values = { Emean, err_Emean, rho, err_rho, phi, err_phi };

            if (etaLow2r9Low2values.count(etaRange.first)==0){
                etaLow2r9Low2values[etaRange.first] = std::map< int, std::vector<float> >();
            }
            etaLow2r9Low2values[etaRange.first][r9Range.first] = values;

        }
        datfile.close();
    }
    else
    {
        std::cout<<"ERROR: reading Egamma Smearing failed!"<<std::endl;
        exit(1);
    }

    std::vector<int> etaVector_low(etaSet_low.begin(), etaSet_low.end());
    std::vector<int> r9Vector_low(r9Set_low.begin(), r9Set_low.end());

    sort(etaVector_low.begin(), etaVector_low.end()); 
    sort(r9Vector_low.begin(), r9Vector_low.end()); 

    _etaVector_low  = etaVector_low;
    _r9Vector_low   = r9Vector_low;
}


#endif

        // for (int i=0;i<nPhoton;i++){

        //     if (!(Photon_isScEtaEB[i] || Photon_isScEtaEE[i])) continue;
        //     if (Photon_cutBasedVersionFreeBitmap[i]==0) continue;
        //     //if (!HLT_PFJet450) continue;

        //     float SCEta = Photon_SCEta(i);
        //     float SCEta2= Photon_SCEta2(i);
        //     float scale = EgammaScaling.get_energyScale(SCEta,Photon_r9[i], static_cast<int>(Photon_seedGain[i]) , run);
        //     float scale2 = EgammaScaling.get_energyScale(SCEta2,Photon_r9[i], static_cast<int>(Photon_seedGain[i]) , run);

        //     correction*=randomgen->Gaus(1,(*phoResol_rho_up)[i]);

        //     if ( (SCEta<2 && SCEta2>2) || (SCEta>2 && SCEta2<2) ){
        //         cout<<"event number: "<<event<<endl;
        //         cout<<"i="<<i<<endl;
        //         cout<<" PV_z: "<<PV_z<<" eta: "<< Photon_eta[i] <<" SCeta: "<< SCEta <<" SCEta2: "<<SCEta2<<endl;
        //         std::cout<<" Photon_pt[i] = "<<Photon_pt[i]<<std::endl;
        //         std::cout<<" Photon_cutBasedVersionFreeBitmap[i] = "<<Photon_cutBasedVersionFreeBitmap[i]<<std::endl;
        //         std::cout<<" Photon_pixelSeed[i] = "<<Photon_pixelSeed[i]<<std::endl;
        //         std::cout<<" Photon_eta[i] = "<<Photon_eta[i]<<std::endl;
        //         std::cout<<" SCEta = "<<SCEta<<std::endl;
        //         std::cout<<" Photon_r9[i] = "<<Photon_r9[i]<<std::endl;
        //         std::cout<<" Photon_seedGain[i] = "<< static_cast<int>(Photon_seedGain[i])<<std::endl;
        //         std::cout<<" run = "<<run<<std::endl;
        //         std::cout<<"Photon_eCorr[i] = "<<Photon_eCorr[i]<<" scale from dat file = "<< scale <<std::endl;
        //         //std::cout<<" Photon_pt[i] = "<<Photon_pt[i]<<" Photon_eCorr[i] = "<<Photon_eCorr[i]<<" Photon_pt[i] / Photon_eCorr[i] = "<< Photon_pt[i] / Photon_eCorr[i]<< " scale = "<< scale <<std::endl;
        //         //exit(1);
        //         std::ifstream datfile("./Legacy2016_07Aug2017_FineEtaR9_v3_ele_unc_scales.dat");
        //         cout<<"Selecting based only on run and scaling:"<<endl;
        //         if (datfile.is_open()) {
        //             std::string s;
        //             while( std::getline(datfile, s) ) {
        //                 std::stringstream ss;
        //                 ss<<s;

        //                 string x;
        //                 int runMin, runMax;
        //                 float scale;

        //                 ss >> x >> x >> runMin >> runMax >> scale;

        //                 //if (runMin<= run && run <=runMax && Photon_eCorr[i]==scale) cout<<s<<endl;
        //                 if (runMin<= run && run <=runMax && abs(Photon_eCorr[i]-scale)/scale<0.0001) cout<<s<<endl;
        //             }
        //         }
        //         cout<<endl<<endl;
        //     }

        //     if ( abs(( Photon_eCorr[i] - scale )/scale) > 0.005 ){//} || event == 318314747 ){//&& Photon_isScEtaEE[i]   static_cast<int>(Photon_seedGain[i]) == 12 &&
        //         goldenJsonEvents++;
        //     }
          

        //     if ( abs(( Photon_eCorr[i] - scale2 )/scale2) > 0.005 ){
        //         goldenJsonEvents2++;
        //     }
        // }

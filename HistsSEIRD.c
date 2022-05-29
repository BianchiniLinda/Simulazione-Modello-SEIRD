#include <TCanvas.h>
#include <TFile.h>
#include <TH1I.h>

void HistsSEIRD(TString filename="isto.root"){
  //Input degli istogrammi dal file riempito nella simulazione
    TFile *filein = new TFile(filename);
    TH1I *histCs = (TH1I*)filein->Get("histCs");
    TH1I *histCe = (TH1I*)filein->Get("histCe");
    TH1I *histCi = (TH1I*)filein->Get("histCi");
    TH1I *histCr = (TH1I*)filein->Get("histCr");
    TH1I *histCd = (TH1I*)filein->Get("histCd");

    TH1I *histYs = (TH1I*)filein->Get("histYs");
    TH1I *histYe = (TH1I*)filein->Get("histYe");
    TH1I *histYi = (TH1I*)filein->Get("histYi");
    TH1I *histYr = (TH1I*)filein->Get("histYr");
    TH1I *histYd = (TH1I*)filein->Get("histYd");

    TH1I *histAs = (TH1I*)filein->Get("histAs");
    TH1I *histAe = (TH1I*)filein->Get("histAe");
    TH1I *histAi = (TH1I*)filein->Get("histAi");
    TH1I *histAr = (TH1I*)filein->Get("histAr");
    TH1I *histAd = (TH1I*)filein->Get("histAd");

    TH1I *histEs = (TH1I*)filein->Get("histEs");
    TH1I *histEe = (TH1I*)filein->Get("histEe");
    TH1I *histEi = (TH1I*)filein->Get("histEi");
    TH1I *histEr = (TH1I*)filein->Get("histEr");
    TH1I *histEd = (TH1I*)filein->Get("histEd");

//Istogrammi dei Susceptible e Ricovered per i bambini

    TCanvas *c1 = new TCanvas();
    histCs->SetLineColor(kGreen);
    histCr->SetLineColor(kOrange);
    histCi->SetLineColor(kRed);
    histCs->Draw("c");
    histCr->Draw("histcsame");
    histCs->GetXaxis()->SetTitle("Days");
    gPad->BuildLegend();
    histCs->GetYaxis()->SetRangeUser(0, 2100);

//Istogrammi degli Infected, Exposed e Death per i bambini

    TCanvas *c2 = new TCanvas();
    histCe->SetLineColor(kBlue);
    histCd->SetLineColor(kBlack);
    histCe->Draw("c");
    histCd->Draw("histcsame");
    histCi->Draw("histcsame");
    histCe->GetXaxis()->SetTitle("Days");
    gPad->BuildLegend();
    histCe->GetYaxis()->SetRangeUser(0, 500);

//Istogrammi dei Susceptible e Ricovered per i giovani

    TCanvas *c3 = new TCanvas();
    histYs->SetLineColor(kGreen);
    histYr->SetLineColor(kOrange);
    histYi->SetLineColor(kRed);
    histYs->Draw("c");
    histYr->Draw("histcsame");
    histYs->GetXaxis()->SetTitle("Days");
    gPad->BuildLegend();
    histYs->GetYaxis()->SetRangeUser(0, 2100);

//Istogrammi degli Infected, Exposed e Death per i giovani

    TCanvas *c4 = new TCanvas();
    histYe->SetLineColor(kBlue);
    histYd->SetLineColor(kBlack);
    histYe->Draw("c");
    histYd->Draw("histcsame");
    histYi->Draw("histcsame");
    histYe->GetXaxis()->SetTitle("Days");
    gPad->BuildLegend();
    histYe->GetYaxis()->SetRangeUser(0, 500);

//Istogrammi dei Susceptible e Ricovered per gli adulti

    TCanvas *c5 = new TCanvas();
    histAs->SetLineColor(kGreen);
    histAr->SetLineColor(kOrange);
    histAi->SetLineColor(kRed);
    histAs->Draw("c");
    histAr->Draw("histcsame");
    histAs->GetXaxis()->SetTitle("Days");
    gPad->BuildLegend();
    histAs->GetYaxis()->SetRangeUser(0, 2100);

//Istogrammi degli Infected, Exposed e Death per gli adulti

    TCanvas *c6 = new TCanvas();
    histAe->SetLineColor(kBlue);
    histAd->SetLineColor(kBlack);
    histAe->Draw("c");
    histAd->Draw("histcsame");
    histAi->Draw("histcsame");
    histAe->GetXaxis()->SetTitle("Days");
    gPad->BuildLegend();
    histAe->GetYaxis()->SetRangeUser(0, 500);

//Istogrammi dei Susceptible e Ricovered per gli anziani

    TCanvas *c7 = new TCanvas();
    histEs->SetLineColor(kGreen);
    histEr->SetLineColor(kOrange);
    histEi->SetLineColor(kRed);
    histEs->Draw("c");
    histEr->Draw("histcsame");
    histEs->GetXaxis()->SetTitle("Days");
    gPad->BuildLegend();
    histEs->GetYaxis()->SetRangeUser(0, 2100);

  //Istogrammi degli Infected, Exposed e Death per gli anziani

    TCanvas *c8 = new TCanvas();
    histEe->SetLineColor(kBlue);
    histEd->SetLineColor(kBlack);
    histEe->Draw("c");
    histEd->Draw("histcsame");
    histEi->Draw("histcsame");
    histEe->GetXaxis()->SetTitle("Days");
    gPad->BuildLegend();
    histEe->GetYaxis()->SetRangeUser(0, 500);




}

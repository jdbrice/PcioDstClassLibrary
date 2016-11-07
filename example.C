

TChain * c = nullptr;
TClonesArray * events = nullptr;
TClonesArray * tracks = nullptr;
TClonesArray * btowHits = nullptr;
TClonesArray * btofHits = nullptr;
TClonesArray * mtdHits = nullptr;



void example( string infile="/Users/jdb/bnl/local/data/Run14/hft/pico/P16id/111/15111067/st_physics_15111067_raw_2000012.picoDst.root" ){

	c = new TChain( "PicoDst" );
	c->Add( infile.c_str() );

	c->SetBranchStatus( "*", 0 );

	gSystem->Load( "StPicoBTOWHit_h.so" );
	gSystem->Load( "StPicoBTofHit_h.so" );
	gSystem->Load( "StPicoBTofPidTraits_h.so" );
	gSystem->Load( "StPicoEmcPidTraits_h.so" );
	gSystem->Load( "StPicoEmcTrigger_h.so" );
	gSystem->Load( "StPicoEvent_h.so" );
	gSystem->Load( "StPicoMtdHit_h.so" );
	gSystem->Load( "StPicoMtdPidTraits_h.so" );
	gSystem->Load( "StPicoMtdTrigger_h.so" );
	gSystem->Load( "StPicoTrack_h.so" );


	events = new TClonesArray( "StPicoEvent" );
	tracks = new TClonesArray( "StPicoTrack" );
	btowHits = new TClonesArray( "StPicoBTOWHit" );
	btofHits = new TClonesArray( "StPicoBTofHit" );
	mtdHits = new TClonesArray( "StPicoMtdHit" );

	c->SetBranchStatus( "Event*", 1 );
	c->SetBranchStatus( "Tracks*", 1 );
	c->SetBranchStatus( "BTOWHit*", 1 );
	c->SetBranchStatus( "BTofHit*", 1 );
	c->SetBranchStatus( "MtdHit*", 1 );

	c->SetBranchAddress( "Event", &events );
	c->SetBranchAddress( "Tracks", &tracks );
	c->SetBranchAddress( "BTOWHit", &btowHits );
	c->SetBranchAddress( "BTofHit", &btofHits );
	c->SetBranchAddress( "MtdHit", &mtdHits );

	cout << c->GetEntry(0) << endl;


}
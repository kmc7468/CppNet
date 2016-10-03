#include "Decimal.h"
using namespace CppNet::KMC;
using namespace System;

// 소수점 아래 10000자리까지 표현
const Decimal Decimal::E = Decimal("2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274274663919320030599218174135966290435729003342952605956307381323286279434907632338298807531952510190115738341879307021540891499348841675092447614606680822648001684774118537423454424371075390777449920695517027618386062613313845830007520449338265602976067371132007093287091274437470472306969772093101416928368190255151086574637721112523897844250569536967707854499699679468644549059879316368892300987931277361782154249992295763514822082698951936680331825288693984964651058209392398294887933203625094431173012381970684161403970198376793206832823764648042953118023287825098194558153017567173613320698112509961818815930416903515988885193458072738667385894228792284998920868058257492796104841984443634632449684875602336248270419786232090021609902353043699418491463140934317381436405462531520961836908887070167683964243781405927145635490613031072085103837505101157477041718986106873969655212671546889570350354021234078498193343210681701210056278802351930332247450158539047304199577770935036604169973297250886876966403555707162268447162560798826517871341951246652010305921236677194325278675398558944896970964097545918569563802363701621120477427228364896134225164450781824423529486363721417402388934412479635743702637552944483379980161254922785092577825620926226483262779333865664816277251640191059004916449982893150566047258027786318641551956532442586982946959308019152987211725563475463964479101459040905862984967912874068705048958586717479854667757573205681288459205413340539220001137863009455606881667400169842055804033637953764520304024322566135278369511778838638744396625322498506549958862342818997077332761717839280349465014345588970719425863987727547109629537415211151368350627526023264847287039207643100595841166120545297030236472549296669381151373227536450988890313602057248176585118063036442812314965507047510254465011727211555194866850800368532281831521960037356252794495158284188294787610852639813955990067376482922443752871846245780361929819713991475644882626039033814418232625150974827987779964373089970388867782271383605772978824125611907176639465070633045279546618550966661856647097113444740160704626215680717481877844371436988218559670959102596862002353718588748569652200050311734392073211390803293634479727355955277349071783793421637012050054513263835440001863239914907054797780566978533580489669062951194324730995876552368128590413832411607226029983305353708761389396391779574540161372236187893652605381558415871869255386061647798340254351284396129460352913325942794904337299085731580290958631382683291477116396337092400316894586360606458459251269946557248391865642097526850823075442545993769170419777800853627309417101634349076964237222943523661255725088147792231519747780605696725380171807763603462459278778465850656050780844211529697521890874019660906651803516501792504619501366585436632712549639908549144200014574760819302212066024330096412704894390397177195180699086998606636583232278709376502260149291011517177635944602023249300280401867723910288097866605651183260043688508817157238669842242201024950551881694803221002515426494639812873677658927688163598312477886520141174110913601164995076629077943646005851941998560162647907615321038727557126992518275687989302761761146162549356495903798045838182323368612016243736569846703785853305275833337939907521660692380533698879565137285593883499894707416181550125397064648171946708348197214488898790676503795903669672494992545279033729636162658976039498576741397359441023744329709355477982629614591442936451428617158587339746791897571211956187385783644758448423555581050025611492391518893099463428413936080383091662818811503715284967059741625628236092168075150177725387402564253470879089137291722828611515915683725241630772254406337875931059826760944203261924285317018781772960235413060672136046000389661093647095141417185777014180606443636815464440053316087783143174440811949422975599314011888683314832802706553833004693290115744147563139997221703804617092894579096271662260740718749975359212756084414737823303270330168237193648002173285734935947564334129943024850235732214597843282641421684878721673367010615094243456984401873312810107945127223737886126058165668053714396127888732527373890392890506865324138062796025930387727697783792868409325365880733988457218746021005311483351323850047827169376218004904795597959290591655470505777514308175112698985188408718564026035305583737832422924185625644255022672155980274012617971928047139600689163828665277009752767069777036439260224372841840883251848770472638440379530166905465937461619323840363893131364327137688841026811219891275223056256756254701725086349765367288605966752740868627407912856576996313789753034660616669804218267724560530660773899624218340859882071864682623215080288286359746839654358856685503773131296587975810501214916207656769950659715344763470320853215603674828608378656803073062657633469774295634643716709397193060876963495328846833613038829431040800296873869117066666146800015121143442256023874474325250769387077775193299942137277211258843608715834835626961661980572526612206797540621062080649882918454395301529982092503005498257043390553570168653120526495614857249257386206917403695213533732531666345466588597286659451136441370331393672118569553952108458407244323835586063106806964924851232632699514603596037297253198368423363904632136710116192821711150282801604488058802382031981493096369596735832742024988245684941273860566491352526706046234450549227581151709314921879592718001940968866986837037302200475314338181092708030017205935530520700706072233999463990571311587099635777359027196285061146514837526209565346713290025994397663114545902685898979115837093419370441155121920117164880566945938131183843765620627846310490346293950029458341164824114969758326011800731699437393506966295712410273239138741754923071862454543222039552735295240245903805744502892246886285336542213815722131163288112052146489805180092024719391710555390113943316681515828843687606961102505171007392762385553386272553538830960671644662370922646809671254061869502143176211668140097595281493907222601112681153108387317617323235263605838173151034595736538223534992935822836851007810884634349983518404451704270189381994243410090575376257767571118090088164183319201962623416288166521374717325477727783488774366518828752156685719506371936565390389449366421764003121527870222366463635755503565576948886549500270853923617105502131147413744106134445544192101336172996285694899193369184729478580729156088510396781959429833186480756083679551496636448965592948187851784038773326247051945050419847742014183947731202815886845707290544057510601285258056594703046836344592652552137008068752009593453607316226118728173928074623094685367823106097921599360019946237993434210687813497346959246469752506246958616909178573976595199392993995567542714654910456860702099012606818704984178079173924071945996323060254707901774527513186809982284730860766536866855516467702911336827563107223346726113705490795365834538637196235856312618387156774118738527722922594743373785695538456246801013905727871016512966636764451872465653730402443684140814488732957847348490003019477888020460324660842875351848364959195082888323206522128104190448047247949291342284951970022601310430062410717971502793433263407995960531446053230488528972917659876016667811937932372453857209607582277178483361613582612896226118129455927462767137794487586753657544861407611931125958512655759734573015333642630767985443385761715333462325270572005303988289499034259566232975782488735029259166825894456894655992658454762694528780516501720674785417887982276806536650641910973434528878338621726156269582654478205672987756426325321594294418039943217000090542650763095588465895171709147607437136893319469090981904501290307099566226620303182649365733698419555776963787624918852865686607600566025605445711337286840205574416030837052312242587223438854123179481388550075689381124935386318635287083799845692619981794523364087429591180747453419551420351726184200845509170845682368200897739455842679214273477560879644279202708312150156406341341617166448069815483764491573900121217041547872591998943825364950514771379399147205219529079396137621107238494290616357604596231253506068537651423115349665683715116604220796394466621163255157729070978473156278277598788136491951257483328793771571459091064841642678309949723674420175862269402159407924480541255360431317992696739157542419296607312393763542139230617876753958711436104089409966089471418340698362993675362621545247298464213752891079884381306095552622720837518629837066787224430195793793786072107254277289071732854874374355781966511716618330881129120245204048682200072344035025448202834254187884653602591506445271657700044521097735585897622655484941621714989532383421600114062950718490427789258552743035221396835679018076406042138307308774460170842688272261177180842664333651780002171903449234264266292261456004337383868335555343453004264818473989215627086095650629340405264943244261445665921291225648893569655009154306426134252668472594914314239398845432486327461842846655985332312210466259890141712103446084271616619001257195870793217569698544013397622096749454185407118446433946990162698351607848924514058940946395267807354579700307051163682519487701189764002827648414160587206184185297189154019688253289309149665345753571427318482016384644832499037886069008072709327673127581966563941148961716832980455139729506687604740915420428429993541025829113502241690769431668574242522509026939034814856451303069925199590436384028429267412573422447765584177886171737265462085498294498946787350929581652632072258992368768457017823038096567883112289305809140572610865884845873101658151167533327674887014829167419701512559782572707406431808601428149024146780472327597684269633935773542930186739439716388611764209004068663398856841681003872389214483176070116684503887212364367043314091155733280182977988736590916659612402021778558854876176161989370794380056663364884365089144805571039765214696027662583599051987042300179465536788");

// 소수점 아래 9098자리까지 표현
const Decimal Decimal::PI = Decimal("3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196442881097566593344612847564823378678316527120190914564856692346034861045432664821339360726024914127372458700660631558817488152092096282925409171536436789259036001133053054882046652138414695194151160943305727036575959195309218611738193261179310511854807446237996274956735188575272489122793818301194912983367336244065664308602139494639522473719070217986094370277053921717629317675238467481846766940513200056812714526356082778577134275778960917363717872146844090122495343014654958537105079227968925892354201995611212902196086403441815981362977477130996051870721134999999837297804995105973173281609631859502445945534690830264252230825334468503526193118817101000313783875288658753320838142061717766914730359825349042875546873115956286388235378759375195778185778053217122680661300192787661119590921642019893809525720106548586327886593615338182796823030195203530185296899577362259941389124972177528347913151557485724245415069595082953311686172785588907509838175463746493931925506040092770167113900984882401285836160356370766010471018194295559619894676783744944825537977472684710404753464620804668425906949129331367702898915210475216205696602405803815019351125338243003558764024749647326391419927260426992279678235478163600934172164121992458631503028618297455570674983850549458858692699569092721079750930295532116534498720275596023648066549911988183479775356636980742654252786255181841757467289097777279380008164706001614524919217321721477235014144197356854816136115735255213347574184946843852332390739414333454776241686251898356948556209921922218427255025425688767179049460165346680498862723279178608578438382796797668145410095388378636095068006422512520511739298489608412848862694560424196528502221066118630674427862203919494504712371378696095636437191728746776465757396241389086583264599581339047802759009946576407895126946839835259570982582262052248940772671947826848260147699090264013639443745530506820349625245174939965143142980919065925093722169646151570985838741059788595977297549893016175392846813826868386894277415599185592524595395943104997252468084598727364469584865383673622262609912460805124388439045124413654976278079771569143599770012961608944169486855584840635342207222582848864815845602850601684273945226746767889525213852254995466672782398645659611635488623057745649803559363456817432411251507606947945109659609402522887971089314566913686722874894056010150330861792868092087476091782493858900971490967598526136554978189312978482168299894872265880485756401427047755513237964145152374623436454285844479526586782105114135473573952311342716610213596953623144295248493718711014576540359027993440374200731057853906219838744780847848968332144571386875194350643021845319104848100537061468067491927819119793995206141966342875444064374512371819217999839101591956181467514269123974894090718649423196156794520809514655022523160388193014209376213785595663893778708303906979207734672218256259966150142150306803844773454920260541466592520149744285073251866600213243408819071048633173464965145390579626856100550810665879699816357473638405257145910289706414011097120628043903975951567715770042033786993600723055876317635942187312514712053292819182618612586732157919841484882916447060957527069572209175671167229109816909152801735067127485832228718352093539657251210835791513698820914442100675103346711031412671113699086585163983150197016515116851714376576183515565088490998985998238734552833163550764791853589322618548963213293308985706420467525907091548141654985946163718027098199430992448895757128289059232332609729971208443357326548938239119325974636673058360414281388303203824903758985243744170291327656180937734440307074692112019130203303801976211011004492932151608424448596376698389522868478312355265821314495768572624334418930396864262434107732269780280731891544110104468232527162010526522721116603966655730925471105578537634668206531098965269186205647693125705863566201855810072936065987648611791045334885034611365768675324944166803962657978771855608455296541266540853061434443185867697514566140680070023787765913440171274947042056223053899456131407112700040785473326993908145466464588079727082668306343285878569830523580893306575740679545716377525420211495576158140025012622859413021647155097925923099079654737612551765675135751782966645477917450112996148903046399471329621073404375189573596145890193897131117904297828564750320319869151402870808599048010941214722131794764777262241425485454033215718530614228813758504306332175182979866223717215916077166925474873898665494945011465406284336639379003976926567214638530673609657120918076383271664162748888007869256029022847210403172118608204190004229661711963779213375751149595015660496318629472654736425230817703675159067350235072835405670403867435136222247715891504953098444893330963408780769325993978054193414473774418426312986080998886874132604721569516239658645730216315981931951673538129741677294786724229246543668009806769282382806899640048243540370141631496589794092432378969070697794223625082216889573837986230015937764716512289357860158816175578297352334460428151262720373431465319777741603199066554187639792933441952154134189948544473456738316249934191318148092777710386387734317720754565453220777092120190516609628049092636019759882816133231666365286193266863360627356763035447762803504507772355471058595487027908143562401451718062464362679456127531813407833033625423278394497538243720583531147711992606381334677687969597030983391307710987040859133746414428227726346594704745878477872019277152807317679077071572134447306057007334924369311383504931631284042512192565179806941135280131470130478164378851852909285452011658393419656213491434159562586586557055269049652098580338507224264829397285847831630577775606888764462482468579260395352773480304802900587607582510474709164396136267604492562742042083208566119062545433721315359584506877246029016187667952406163425225771954291629919306455377991403734043287526288896399587947572917464263574552540790914513571113694109119393251910760208252026187985318877058429725916778131496990090192116971737278476847268608490033770242429165130050051683233643503895170298939223345172201381280696501178440874519601212285993716231301711444846409038906449544400619869075485160263275052983491874078668088183385102283345085048608250393021332197155184306354550076682829493041377655279397517546139539846833936383047461199665385815384205685338621867252334028308711232827892125077126294632295639898989358211674562701021835646220134967151881909730381198004973407239610368540664319395097901906996395524530054505806855019567302292191393391856803449039820595510022635353619204199474553859381023439554495977837790237421617271117236434354394782218185286240851400666044332588856986705431547069657474585503323233421073015459405165537906866273337995851156257843229882737231989875714159578111963583300594087306812160287649628674460477464915995054973742562690104903778198683593814657412680492564879855614537234786733039046883834363465537949864192705638729317487233208376011230299113679386270894387993620162951541337142489283072201269014754668476535761647737946752004907571555278196536213239264061601363581559074220202031872776052772190055614842555187925303435139844253223415762336106425063904975008656271095359194658975141310348227693062474353632569160781547818115284366795706110861533150445212747392454494542368288606134084148637767009612071512491404302725386076482363414334623518975766452164137679690314950191085759844239198629164219399490723623464684411739403265918404437805133389452574239950829659122850855582157250310712570126683024029295252201187267675622041542051618416348475651699981161410100299607838690929160302884002691041407928862150784245167090870006992821206604183718065355672525325675328612910424877618258297651579598470356222629348600341587229805349896502262917487882027342092222453398562647669149055628425039127577102840279980663658254889264880254566101729670266407655904290994568150652653053718294127033693137851786090407086671149655834343476933857817113864558736781230145876871266034891390956200993936103102916161528813843790990423174733639480457593149314052976347574811935670911013775172100803155902485309066920376719220332290943346768514221447737939375170344366199104033751117354719185504644902636551281622882446257591633303910722538374218214088350865739177150968288747826569959957449066175834413752239709683408005355984917541738188399944697486762655165827658483588453142775687900290951702835297163445621296404352311760066510124120065975585127617858382920419748442360800719304576189323492292796501987518721272675079812554709589045563579212210333466974992356302549478024901141952123828153091140790738602515227429958180724716259166854513331239480494707911915326734302824418604142636395480004480026704962482017928964766975831832713142517029692348896276684403232609275249603579964692565049368183609003238092934595889706953653494060340216654437558900456328822505452556405644824651518754711962184439658253375438");

Decimal::Decimal()
{
	mInteger.push_back(0);
	mReal.push_back(0);
}

Decimal::Decimal(const String& str)
	: Decimal(Parse(str))
{ }

Decimal::Decimal(Int64 integer)
	: Decimal(std::to_string(integer))
{}

Decimal::Decimal(Int64 integer, const String& real)
	: Decimal(std::to_string(integer) + "." + real)
{}

Decimal::Decimal(Double real)
	: Decimal(std::to_string(real))
{}

Decimal::Decimal(Decimal&& d)
{
	mInteger = d.mInteger;
	mReal = d.mReal;
	isN = d.isN;

	Clean();
}

Decimal::Decimal(const Decimal& d)
{
	mInteger = d.mInteger;
	mReal = d.mReal;
	isN = d.isN;

	Clean();
}

Decimal Decimal::Parse(const String& str)
{
	Decimal r;

	String s(str);

	if (s[0] == '-')
	{
		r.isN = true;
		s.erase(s.begin());
	}

	if (s.find('.') == String::npos)
	{
		s.insert(0, s.length() & 1, '0');

		int n = s.length() >> 1;
		for (size_t i = 0; i < n; i++)
			r.mInteger += ByteTool::IntsToByte(ByteTool::ToByte(s[i << 1]), ByteTool::ToByte(s[(i << 1) + 1]));

		r.mReal += (Byte)0;
	}
	else
	{
		size_t dot = s.find('.');

		String integer = s.substr(0, dot);
		String real = s.substr(dot + 1);

		integer.insert(0, integer.length() & 1, '0');
		real.append(real.length() & 1, '0');

		for (size_t i = 0; i < integer.length() >> 1; i++)
		{
			Byte first = ByteTool::ToByte(integer[i << 1]);
			Byte second = ByteTool::ToByte(integer[(i << 1) + 1]);
			Byte c = ByteTool::IntsToByte(first, second);
			r.mInteger += c;
		}

		for (size_t i = 0; i < real.length() >> 1; i++)
		{
			Byte first = ByteTool::ToByte(real[i << 1]);
			Byte second = ByteTool::ToByte(real[(i << 1) + 1]);
			Byte c = ByteTool::IntsToByte(first, second);
			if (i == 0)
				r.mReal = c;
			else
				r.mReal += c;
		}
	}

	r.Clean();

	return r;
}

Boolean Decimal::operator==(const Object& obj) const
{
	if (is<const Decimal, std::remove_reference<const Object&>::type>())
	{
		var a = as<const Decimal&>(obj);

		if (a.ToString() == (*this).ToString())
			return true;
		else
			return false;
	}
	else
		return false;
}

Boolean Decimal::operator!=(const Object& obj) const
{
	return !Decimal::operator==(obj);
}

Boolean Decimal::operator>(const Decimal& d) const
{
	Decimal a = *this;
	Decimal b = d;

	if (a.isN && !b.isN) return false;
	else if (!a.isN && b.isN) return true;

	// 패딩

	if (a.mReal.length() >= b.mReal.length())
		b.mReal.insert(b.mReal.length(), a.mReal.length() - b.mReal.length(), 0);
	else
		a.mReal.insert(a.mReal.length(), b.mReal.length() - a.mReal.length(), 0);

	if (a.mInteger.length() >= b.mInteger.length())
		b.mInteger.insert(0, a.mInteger.length() - b.mInteger.length(), 0);
	else
		a.mInteger.insert(0, b.mInteger.length() - a.mInteger.length(), 0);

	// 체크

	for (size_t i = 0; i < a.mInteger.length(); i++)
	{
		var temp_a = ByteTool::ByteToInts(a.mInteger[i]);
		var temp_b = ByteTool::ByteToInts(b.mInteger[i]);

		var a_one = std::get<0>(temp_a);
		var a_two = std::get<1>(temp_a);

		var b_one = std::get<0>(temp_b);
		var b_two = std::get<1>(temp_b);

		if ((!a.isN && a_one > b_one) || (a.isN && a_one < b_one)) return true;

		if ((!a.isN && a_two > b_two) || (a.isN && a_two < b_two)) return true;
	}

	for (size_t i = 0; i < a.mReal.length(); i++)
	{
		var temp_a = ByteTool::ByteToInts(a.mReal[i]);
		var temp_b = ByteTool::ByteToInts(b.mReal[i]);

		var a_one = std::get<0>(temp_a);
		var a_two = std::get<1>(temp_a);

		var b_one = std::get<0>(temp_b);
		var b_two = std::get<1>(temp_b);

		if ((!a.isN && a_one > b_one) || (a.isN && a_one < b_one)) return true;

		if ((!a.isN && a_two > b_two) || (a.isN && a_two < b_two)) return true;
	}

	return false;
}

Boolean Decimal::operator>=(const Decimal& d) const
{
	Decimal a = *this;
	Decimal b = d;

	if (a.isN && !b.isN) return false;
	else if (!a.isN && b.isN) return true;

	// 패딩

	if (a.mReal.length() >= b.mReal.length())
		b.mReal.insert(b.mReal.length(), a.mReal.length() - b.mReal.length(), 0);
	else
		a.mReal.insert(a.mReal.length(), b.mReal.length() - a.mReal.length(), 0);

	if (a.mInteger.length() >= b.mInteger.length())
		b.mInteger.insert(0, a.mInteger.length() - b.mInteger.length(), 0);
	else
		a.mInteger.insert(0, b.mInteger.length() - a.mInteger.length(), 0);

	// 체크

	for (size_t i = 0; i < a.mInteger.length(); i++)
	{
		var temp_a = ByteTool::ByteToInts(a.mInteger[i]);
		var temp_b = ByteTool::ByteToInts(b.mInteger[i]);

		var a_one = std::get<0>(temp_a);
		var a_two = std::get<1>(temp_a);

		var b_one = std::get<0>(temp_b);
		var b_two = std::get<1>(temp_b);

		if ((!a.isN && a_one >= b_one) || (a.isN && a_one <= b_one)) return true;

		if ((!a.isN && a_two >= b_two) || (a.isN && a_two <= b_two)) return true;
	}

	for (size_t i = 0; i < a.mReal.length(); i++)
	{
		var temp_a = ByteTool::ByteToInts(a.mReal[i]);
		var temp_b = ByteTool::ByteToInts(b.mReal[i]);

		var a_one = std::get<0>(temp_a);
		var a_two = std::get<1>(temp_a);

		var b_one = std::get<0>(temp_b);
		var b_two = std::get<1>(temp_b);

		if ((!a.isN && a_one >= b_one) || (a.isN && a_one <= b_one)) return true;

		if ((!a.isN && a_two >= b_two) || (a.isN && a_two <= b_two)) return true;
	}

	return false;
}

Boolean Decimal::operator<(const Decimal& d) const
{
	Decimal a = *this;
	Decimal b = d;

	if (!a.isN && b.isN) return false;
	else if (a.isN && !b.isN) return true;

	// 패딩

	if (a.mReal.length() >= b.mReal.length())
		b.mReal.insert(b.mReal.length(), a.mReal.length() - b.mReal.length(), 0);
	else
		a.mReal.insert(a.mReal.length(), b.mReal.length() - a.mReal.length(), 0);

	if (a.mInteger.length() >= b.mInteger.length())
		b.mInteger.insert(0, a.mInteger.length() - b.mInteger.length(), 0);
	else
		a.mInteger.insert(0, b.mInteger.length() - a.mInteger.length(), 0);

	// 체크

	for (size_t i = 0; i < a.mInteger.length(); i++)
	{
		var temp_a = ByteTool::ByteToInts(a.mInteger[i]);
		var temp_b = ByteTool::ByteToInts(b.mInteger[i]);

		var a_one = std::get<0>(temp_a);
		var a_two = std::get<1>(temp_a);

		var b_one = std::get<0>(temp_b);
		var b_two = std::get<1>(temp_b);

		if ((!a.isN && a_one < b_one) || (a.isN && a_one > b_one)) return true;

		if ((!a.isN && a_two < b_two) || (a.isN && a_two > b_two)) return true;
	}

	for (size_t i = 0; i < a.mReal.length(); i++)
	{
		var temp_a = ByteTool::ByteToInts(a.mReal[i]);
		var temp_b = ByteTool::ByteToInts(b.mReal[i]);

		var a_one = std::get<0>(temp_a);
		var a_two = std::get<1>(temp_a);

		var b_one = std::get<0>(temp_b);
		var b_two = std::get<1>(temp_b);

		if ((!a.isN && a_one < b_one) || (a.isN && a_one > b_one)) return true;

		if ((!a.isN && a_two < b_two) || (a.isN && a_two > b_two)) return true;
	}

	return false;
}

Boolean Decimal::operator<=(const Decimal& d) const
{
	Decimal a = *this;
	Decimal b = d;

	if (!a.isN && b.isN) return false;
	else if (a.isN && !b.isN) return true;

	// 패딩

	if (a.mReal.length() >= b.mReal.length())
		b.mReal.insert(b.mReal.length(), a.mReal.length() - b.mReal.length(), 0);
	else
		a.mReal.insert(a.mReal.length(), b.mReal.length() - a.mReal.length(), 0);

	if (a.mInteger.length() >= b.mInteger.length())
		b.mInteger.insert(0, a.mInteger.length() - b.mInteger.length(), 0);
	else
		a.mInteger.insert(0, b.mInteger.length() - a.mInteger.length(), 0);

	// 체크

	for (size_t i = 0; i < a.mInteger.length(); i++)
	{
		var temp_a = ByteTool::ByteToInts(a.mInteger[i]);
		var temp_b = ByteTool::ByteToInts(b.mInteger[i]);

		var a_one = std::get<0>(temp_a);
		var a_two = std::get<1>(temp_a);

		var b_one = std::get<0>(temp_b);
		var b_two = std::get<1>(temp_b);

		if ((!a.isN && a_one <= b_one) || (a.isN && a_one >= b_one)) return true;

		if ((!a.isN && a_two <= b_two) || (a.isN && a_two >= b_two)) return true;
	}

	for (size_t i = 0; i < a.mReal.length(); i++)
	{
		var temp_a = ByteTool::ByteToInts(a.mReal[i]);
		var temp_b = ByteTool::ByteToInts(b.mReal[i]);

		var a_one = std::get<0>(temp_a);
		var a_two = std::get<1>(temp_a);

		var b_one = std::get<0>(temp_b);
		var b_two = std::get<1>(temp_b);


		if ((!a.isN && a_one <= b_one) || (a.isN && a_one >= b_one)) return true;

		if ((!a.isN && a_two <= b_two) || (a.isN && a_two >= b_two)) return true;
	}

	return false;
}

Decimal& Decimal::operator=(const Decimal& d)
{
	mInteger = d.mInteger;
	mReal = d.mReal;
	isN = d.isN;

	Clean();

	return *this;
}
Decimal& Decimal::operator=(Decimal&& d)
{
	mInteger = std::move(d.mInteger);
	mReal = std::move(d.mReal);
	isN = std::move(d.isN);

	Clean();

	return *this;
}

String Decimal::ToString() const
{
	String integer = "";

	for (var i = mInteger.begin(); i < mInteger.end(); i++)
	{
		var a = ByteTool::ByteToInts(i[0]);

		var one = std::get<0>(a);
		var two = std::get<1>(a);

		integer += ByteTool::FromByte(one);
		integer += ByteTool::FromByte(two);
	}

	while (integer[0] == '0' && integer.length() > 1)
		integer = integer.substr(1);

	String real = "";

	for (var b : mReal)
	{
		var a = ByteTool::ByteToInts(b);

		var one = std::get<0>(a);
		var two = std::get<1>(a);

		real += ByteTool::FromByte(one);
		real += ByteTool::FromByte(two);
	}

	while (real[real.length() - 1] == '0' && real.length() > 1)
		real = real.substr(0, real.length() - 1);

	if (isN)
		integer = "-" + integer;

	if (real == "0")
		return integer;

	if (real != "")
		return integer + "." + real;

	return integer;
}

Decimal Decimal::operator+(const Decimal& d) const
{
	Decimal a = *this;
	Decimal b = Decimal(d);
	Decimal c = 0.0;
	c.mInteger = std::basic_string<Byte, std::char_traits<Byte>, std::allocator<Byte>>();
	c.mReal = std::basic_string<Byte, std::char_traits<Byte>, std::allocator<Byte>>();

	if (a.mReal.length() >= b.mReal.length())
		b.mReal.insert(b.mReal.length(), a.mReal.length() - b.mReal.length(), 0);
	else
		a.mReal.insert(a.mReal.length(), b.mReal.length() - a.mReal.length(), 0);

	Byte up = 0;

	// 둘다 음수이거나 들다 양수일 때
	if (!a.isN && !b.isN || a.isN && b.isN)
	{
		c.isN = a.isN;

		{ // Real
			for (size_t i = a.mReal.length() - 1; i >= 0; i--)
			{
				var temp01 = ByteTool::ByteToInts(a.mReal[i]);

				var one_a = std::get<0>(temp01);
				var two_a = std::get<1>(temp01);

				var temp02 = ByteTool::ByteToInts(b.mReal[i]);

				var one_b = std::get<0>(temp02);
				var two_b = std::get<1>(temp02);

				Byte temp04 = two_a + two_b + up;
				up = temp04 > 9 ? 1 : 0;
				if (up != 0) temp04 -= 10;

				Byte temp03 = one_a + one_b + up;
				up = temp03 > 9 ? 1 : 0;
				if (up != 0) temp03 -= 10;

				c.mReal.insert(0, 1, ByteTool::IntsToByte(temp03, temp04));

				if (i == 0) break; // NOTE: size_t = unsigned long long이기 때문에 음수를 처리 못해서
			}
		}

		if (a.mInteger.length() >= b.mInteger.length())
			b.mInteger.insert(0, a.mInteger.length() - b.mInteger.length(), 0);
		else
			a.mInteger.insert(0, b.mInteger.length() - a.mInteger.length(), 0);

		{ // Integer
			for (size_t i = a.mInteger.length() - 1; i >= 0; i--)
			{
				var temp01 = ByteTool::ByteToInts(a.mInteger[i]);

				var one_a = std::get<0>(temp01);
				var two_a = std::get<1>(temp01);

				var temp02 = ByteTool::ByteToInts(b.mInteger[i]);

				var one_b = std::get<0>(temp02);
				var two_b = std::get<1>(temp02);

				Byte temp04 = two_a + two_b + up;
				up = temp04 > 9 ? 1 : 0;
				if (up != 0) temp04 -= 10;

				Byte temp03 = one_a + one_b + up;
				up = temp03 > 9 ? 1 : 0;
				if (up != 0) temp03 -= 10;

				c.mInteger.insert(0, 1, ByteTool::IntsToByte(temp03, temp04));

				if (i == 0) break; // NOTE: size_t = unsigned long long이기 때문에 음수를 처리 못해서
			}

			c.mInteger = ByteTool::IntsToByte(0, up) + c.mInteger;
		}
	}
	// a가 양수일 때
	else if (!a.isN && b.isN)
	{
		Decimal d = b;
		d.isN = false;
		c = a - d;
	}
	// b가 양수일 때
	else if (a.isN && !b.isN)
	{
		Decimal d = a;
		d.isN = false;
		c = b - d;
	}

	c.Clean();

	return c;
}

Decimal Decimal::operator+=(const Decimal& d)
{
	Decimal a = *this + d;

	mInteger = a.mInteger;
	mReal = a.mReal;

	return *this;
}

Decimal Decimal::operator++()
{
	Decimal a = *this + 1.0;

	mInteger = a.mInteger;

	return *this;
}
Decimal Decimal::operator++(int)
{
	Decimal a = *this + 1.0;
	Decimal b = *this;

	mInteger = a.mInteger;

	return b;
}

Decimal Decimal::operator-(const Decimal& d) const
{
	if (isN && !d.isN)
	{
		Decimal d_t = d;
		d_t.isN = true;
		return this->operator+(d_t);
	}
	else if (isN && d.isN)
	{
		Decimal d_t = d;
		d_t.isN = false;
		return this->operator+(d_t);
	}
	else if (!isN && d.isN)
	{
		Decimal d_t = d;
		d_t.isN = false;
		return this->operator+(d_t);
	}
	bool sign = this->operator>=(d);
	Decimal bigger = sign ? *this : d, smaller = sign ? d : *this;
	//패딩
	smaller.mInteger.insert(smaller.mInteger.begin(), bigger.mInteger.length() - smaller.mInteger.length(), 0x00);

	//소수부분 패딩은 자릿수 계산 후에
	bool t = bigger.mReal.length() >= smaller.mReal.length();
	Decimal* shorter = t ? &smaller : &bigger, *longer = t ? &bigger : &smaller;
	shorter->mReal.append(longer->mReal.length() - shorter->mReal.length(), 0x00);

	//소수부분부터 보수로 변환
	//reverse iterator을 사용하는 이유는 끝부터 0이 아님을 체크하기 때문
	auto revit = std::find_if(
		smaller.mReal.rbegin(), smaller.mReal.rend(),
		[](auto byte)
	{
		return (bool) byte;
	}
	);
	//t가 false이면 소수 부분이 0인 경우입니다
	if (t = revit != smaller.mReal.rend())
	{
		if (!(*revit & 0x0F))
		{
			*revit = (10 - (*revit >> 4)) << 4;
			++revit;
		}
		else
			*revit -= 1;
	}
	for (; revit != smaller.mReal.rend(); ++revit)
		*revit = (9 - (*revit >> 4)) << 4 | (9 - (*revit & 0x0F));
	//소수 변환 완료

	//소수부분이 0일 경우 정수부분에서도 0을 무시해줘야 합니다
	revit = smaller.mInteger.rbegin();
	if (!t)
	{
		revit = std::find_if(revit, smaller.mInteger.rend(),
			[](auto byte)
		{
			return (bool)byte;
		}
		);
		if (revit != smaller.mInteger.rend())
		{
			if (!(*revit & 0x0F))
			{
				*revit = (10 - (*revit >> 4)) << 4;
				++revit;
			}
			else
				*revit -= 1;
		}
	}
	//revit이 처음부터 rend일 경우 따로 처리를 안 해줘도 됩니다.
	for (; revit != smaller.mInteger.rend(); ++revit)
		*revit = (9 - (*revit >> 4)) << 4 | (9 - (*revit & 0x0F));
	
	//맨 앞쪽은 0 ? 혹은 ? ? 이므로
	//0 ?일 경우 지워줍니다.
	if (!(bigger.mInteger[0] >> 4))
		smaller.mInteger[0] &= 0x0F;

	Decimal& ret = bigger + smaller;
	//맨 앞자리는 0 1 혹은 1 ? 입니다.
	//1을 지워줍니다.
	if (ret.mInteger[0] >> 4)
		ret.mInteger[0] &= 0x0F;
	else if (ret.mInteger.length() != 1)
		ret.mInteger.erase(ret.mInteger.begin());

	//부호도 빼먹으면 안됩니다.
	ret.isN = !sign;

	return ret;
}

Decimal Decimal::operator*(const Decimal& d) const
{
	Decimal a = *this;
	Decimal b = d;
	Decimal result;

	a.Clean();
	b.Clean();

	a.mInteger += a.mReal;
	b.mInteger += b.mReal;

	Decimal count_real_size = Decimal(std::to_string((a.mReal.length() * 2) + (b.mReal.length() * 2)));

	a.mReal = '0';
	b.mReal = '0';

	if (a.mInteger.length() >= b.mInteger.length())
		b.mInteger.insert(b.mInteger.length(), a.mInteger.length() - b.mInteger.length(), 0);
	else
		a.mInteger.insert(a.mInteger.length(), b.mInteger.length() - a.mInteger.length(), 0);

	// TODO

	return result;
}
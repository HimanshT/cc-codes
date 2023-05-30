//kmp algorithm

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void kmp(string text, string pattern)
{
	//prefix table
	int t = text.length();
	int p = pattern.length();
	int index = -1;
	int prefix[p];
	memset(prefix, 0, sizeof(prefix));
	int len = 0, i = 1;
	while (i < p)
	{
		if (pattern[len] == pattern[i])
		{
			len++;
			prefix[i] = len;
			i++;
		} else {
			if (len > 0)
			{
				len = prefix[len - 1];
			} else {
				i++;
			}
		}
	}

	for (int i = 0; i < p; i++)
		cout << prefix[i] << " ";
	cout << "\n";

	//checking the pattern
	len = 0;
	i = 0;
	while (i < t)
	{
		if (text[i] == pattern[len])
		{
			i++, len++;
			if (len == p)
			{
				len = prefix[len - 1];
				cout << i << " " << len << endl;
				index = i - p ;
			}
		} else {
			if (len == 0)
				i++;
			else
				len = prefix[len - 1];
		}
	}
	cout << index;
}

int main()
{
	int test = 1;
	while (test--)
	{
		string text = "DASDCBAABAACAABAAD";
		string pattern = "qxnjbnuxzlbpojukgycahvtpuskydgrweefftzesmhicqenyepblnubhmnfsuwoactfvulqisalkeykjplucgxjulomhmchoxomrzcatcldilnrabodhlobyfqfrsmiqaujbyluawzkjpckqqpxddaeksjcnymfyiocgcwiawsklwudolasqcwbxhfkfrpgbfihhgriejsrgouuzwopbmsyuxibqzhreryoypyebswjgsfhpwyqitqeqyghzpydhztfqrlrjhcrciargbjoubvmzbtaqsdztzgjssbebfxdpywvbhmxihjjkdjcxpcqoizgackciihxietjlhgwopfyupcreejunjcpnntvxbvhhqsuxaqlrwlmnnftupnjypyleujdxekeucatcrgupticgnvccklcbmqgizlffwlbalufecbtvjvbwsgbcrdefvmnuxsbtfewrybvacpvnmzjfhmhysngnztkxmlstqqkqritvzqilruqyiazapfopaaomliidzswsarqzhynbufzdhafxhvoivcwjmeolxkgzbwblwqmrvnwdodavzofuscdegssfeyhiwktsaflvujaknagmqngipmpygjdmjkufunxwulspuszjvhvlxewmsnkawqmfchmzwlvtwnitijcftasqeqeydpybhkijruiqgejettxdeaixabpgruexlcauojdidmylshqncnrgpzgrcvzwrfvejvyyecgkqgxkpnxrdoxuqdmubnsutnzclxapbibtozfdoduttuolxcgapyvioulztnqxwusmvyqjbkdwetievoekobtevgdrvwotqiglgwwjibgpuovpezasdvzydcryahsqqadwwaiebovyeqniqpcvmbtpgnqgukxkkajgctmghielytvqjxlvzhnhudnqnmdzpohrhtzqdddcxyuivgfwpsdlvtdkfgjwuqqdmpvpvytuwocuwhsncyyxrdkykvvgolmaahrvglrebtazdtmfrmekpoizmdiaoucrbtojggqhbqgelulegqqygzzuehutdwmhsaqagiiibqoonattsltaktvparkgowniyfifosprlffyhatzmnawgxnioxoevbmuhxbxrsocxvafwweijggrfwzuvqyrtnncmozdgpgflikjgrtpzbifxkbtabmtobwapxgxpmecwpldigujhfqhprcrtqmjrkmiishzglbecohkuewdjmkaemrzedkvowdyokxwwabyoklkojnzvyzbmqcrwnokjskacjwajzbzkojaxyauwzwlsyeonsaxmkzrvxrexufjiqjholcnlayfaetoytnlfmcajvgiqnradbkrmmezoceoizehuruzfybptjxlwrozuyrgkviaaookovrimnkulnjfxistzgvvemeqjmqlahwqepzqdlmqyvxvgqrhwoddchvlvmzxvxozmprraekabhyjxprwfwbhdwuaitxfqlgfcyyceifhqdrpuilzgogllalvwibowjtyjudncivulmkhwxgcmonzqaumivdgfwfoskexubrfpdolduprieqaeknoiqxpoefjojgimxpbddogzfxjjnjpzyghqfyfjeqxpwhcvyfybwecbdlnsuestkbjpaqagizxegzaghyjdfleiwtbtyvokwzcyscgacefkffrmfarkmyvkrydpttarteslgylkcsvizmwfoorcmmndmsvfmxzhbrshpfssypcxdycrmwwykjexdzcrybyzusikyaewrgvugymtwitgtzfyykqwlqxilgsjiyhaecukcifasbhnammbwezkwxshdmsnkbnqgkciskjnlsalgomfuoprljaqxtdjwtzcddlxnwkyqnmwbydwoupzdprckvlhqmjtqwqfudemqslrsophjggoyyriverlrdgjbwoyzukrmvjhmaovhujhucprhjeaoklpjbpkyacmxntjphgyesfauxsdgyfujqluubesdgecvyolhwjlopolmiouguormblgeqyjyfoufcfmaoapdqaryqlembyzdjhjbgvanjusnbgnricxyeowvadhbbigkqsmynolwkfjllycudzshqrequotvwchowvmjjzhtesgsqlotkidczhsvxosusckoxxxjygefylxownkivnlxufustnonraboxaxygcdepcvnrfvmsiloogijvyxmzacybcwhgbovfjiwoflioyyeghnbhmpgnufowdxchlzowhlmoyucwtgdcwgjiysvszloejslwratanfoncrjxzozvxkgvedpdpdiaxvwoxromxezbvlyxzzuwlctqgitxndxkbvyaponotopqznpzokxzmrpuzlrnqqzroyudohrjviaxxpwlbvkqmckoncdfuczictnrcgazocwlusyxojncnysccvhyyghczwtbdwbraxfwsduiohmbhfdjaliatrdtnywswzkxzrtrunbjxpmeuqqxdaxwrcrgbozxnlwmcqfyfgjcywhsmzprzpnsrfauvbsimovqgcpmlyqjuzbiytbzirrbwswttqbieyynbpzoqrxmraxrtyrdpifncdgytkgzigmlwnzofyayzxpuygyprfdtilrdxzcggrteevsltujuuzpshnjaumweanhxplfvcbbhwvsrpemjdddmqnnmblqdaxbpkiknjnuhiobyspjxspmkcbwfmmlmlm";
		kmp(text, pattern);
	}
	return 0;
}
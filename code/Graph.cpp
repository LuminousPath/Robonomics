#include "Graph.h"

Graph::Graph(){
    //meta level               
    addKey("type","node","type","string");
    //firm level
    addKey("cycleNum","node","cycleNum","string");
    addKey("numFirms","node","numFirms","string");
    addKey("numIndividuals","node","numIndividuals","string");
    addKey("avgProductivity","node","avgProductivity","string");
    addKey("unitsLeft","node","unitsLeft","string");
    addKey("capital","node","capital","string");
    addKey("firmId","node","firmId","string");
    //individual level    
    addKey("productivity","node","firmId","productivity");
}

std::string Graph::getNodes(){     
    std::string temp;
    for(int i = 0; i < nodes.size(); i++) temp +=nodes.at(i).value;
    return temp;
}

int Graph::GenerateNodeId()
{
    static int nodeID = 0;
    return nodeId++;
}

int Graph::GenerateEdgeId()
{
    return edgeId++;
}
int Graph::GenerateKeyId()
{
    return keyId++;
}


std::string Graph::getEdges(){   
    std::string temp;
    for(int i = 0; i < edges.size(); i++) temp += edges.at(i).value;
    return temp;
}

std::string Graph::getKeys(){   
    std::string temp;
    for(int i = 0; i < keys.size(); i++) temp += keys.at(i).value;
    return temp;
}

std::string Graph::getGraph(){
    std::string temp;
    temp += str_gdef;
    temp += getKeys();
    temp += str_head;
    temp += getNodes();
    temp += getEdges();
    temp += str_foot;
    return temp;
}

void Graph::addKey(std::string keyId, std::string keyFor,std::string attrName, std::string attrType){
    std::string temp = str_gkey;
    find_replace(temp, str_keyid,keyId);
    find_replace(temp, str_keyfor,keyFor);
    find_replace(temp, str_attrname,attrName);
    find_replace(temp, str_attrtype,attrType);
    keys.push_back(ID(keyId,temp));
}

std::string Graph::getDataKey(std::string keyId, std::string value){
    std::string temp = str_datakey;
    find_replace(temp, str_key, keyId);
    find_replace(temp, str_value, value);
    return temp;
}

void Graph::addNode(std::string dataKeys,std::string prefix){            
    std::string temp = str_node;
    std::string id = prefix+"-Node-"+intToStr(GenerateNodeId());
    find_replace(temp, str_nodeid, id);
    find_replace(temp,str_datakeys,dataKeys);    
    nodes.push_back(ID(id,temp));
}

void Graph::addEdge(std::string target, std::string source, std::string label,std::string prefix){
    std::string temp = str_edge;
    std::string id = prefix+"-Edge-"+intToStr(GenerateNodeId());
    find_replace(temp, str_edgeid, id);
    find_replace(temp, str_source, source);
    find_replace(temp, str_target, target);
    find_replace(temp, str_label, label);    
    edges.push_back(ID(id,temp));
}

void Graph::addCycle(int cycleNum, int fCount){
    std::string dk = getDataKey("type","cycle");
    dk += getDataKey("cycleNum",intToStr(cycleNum));
    dk += getDataKey("numFirms",intToStr(fCount));
    addNode(dk, "Cycle-"+intToStr(cycleNum));
    cycles.push_back(nodes.back());
    if(cycles.size() >= 2){
        addEdge(cycles.at(cycles.size()-1).id,cycles.at(cycles.size()-2).id,str_nextcycle,("NEXT_CYCLE-"+intToStr(cycleNum)));
    }
}

void Graph::addFirms(int cycleNum, std::vector<Firm*> firms){
     for(int i = 0; i < firms.size();i++){
             std::string dk = getDataKey("type","firm");
             dk += getDataKey("cycleNum",intToStr(cycleNum));
             Firm* firm = firms.at(i);
             dk+= getDataKey("numIndividuals",intToStr((int)firm->employees.size()));
             dk+= getDataKey("avgProductivity",intToStr(firm->getproductivity()));
             dk+= getDataKey("unitsLeft",intToStr((int)firm->unitsLeft));
             dk+= getDataKey("capital",intToStr(firm->capital));
             dk+= getDataKey("firmId",intToStr(firm->id));
             addNode(dk,"Cycle-"+intToStr(cycleNum)+"-Firm-"+intToStr(firm->id)); 
             std::string thisCycle = cycles.at(cycles.size()-1).id;
             std::string thisFirm = nodes.at(nodes.size()-1).id;
             addEdge(thisCycle,thisFirm, str_existsin,(str_existsin+"-"+intToStr(cycleNum))); 
             
             
             addIndividuals(cycleNum,firm,thisFirm); 
     }
     buildTrades(cycleNum,firms);
}

void Graph::addUnemployed(int cycleNum, std::vector<Individual*> unemployed){
     for(int i = 0; i < unemployed.size();i++){
             std::string dk = getDataKey("type","individual");
             dk += getDataKey("cycleNum",intToStr(cycleNum));
             dk += getDataKey("productivity", "0");
             addNode(dk,"Unemployed"); 
             std::string thisPerson = nodes.at(nodes.size()-1).id;
             std::string thisCycle = cycles.at(cycles.size()-1).id;
             addEdge(thisCycle , thisPerson, str_existsin,(str_existsin+"-"+intToStr(cycleNum))); 
     }
}

void Graph::addIndividuals(int cycleNum, Firm* firm, std::string firmNode){
     for(int i = 0; i < firm->employees.size();i++){
             std::string dk = getDataKey("type","individual");
             dk += getDataKey("cycleNum",intToStr(cycleNum));
             dk += getDataKey("productivity", intToStr(firm->employees.at(i)->getproductivity(firm->companyProduct)));
             addNode(dk,"Individual-"+intToStr(firm->id)); 
             std::string thisPerson = nodes.at(nodes.size()-1).id;
             addEdge(firmNode, thisPerson, str_worksfor,(str_worksfor+"-"+intToStr(cycleNum))); 
     }
}

void Graph::buildTrades(int cycleNum, std::vector<Firm*> firms){
     
     // find firm
     // find partner
     // build edge
     for(int i = 0; i < firms.size();i++){
         Firm* firm = firms.at(i);
         int id = firm->id;
         int bfId = firm->buysFrom->id;
         std::string node0_Id = "Cycle-"+intToStr(cycleNum)+"-Firm-"+intToStr(id);
         std::string node1_Id = "Cycle-"+intToStr(cycleNum)+"-Firm-"+intToStr(bfId);
         size_t found;
         std::string thisFirm;
         std::string thatFirm;
         bool inFound = false;
         bool outFound = false;
         for(int k = 0; k < nodes.size();k++){
             thisFirm = nodes.at(k).id;
             found=thisFirm.find(node0_Id);
             if (found!=std::string::npos){
                   inFound = true;
                   break;                                            
             }
         }
         found = std::string::npos;
         if(inFound)
             for(int k = 0; k < nodes.size();k++){
                 thatFirm = nodes.at(k).id;
                 found=thatFirm.find(node1_Id);
                 if (found!=std::string::npos){
                       outFound = true; 
                       break;                                            
                 }
             }
         if(outFound) addEdge(thatFirm , thisFirm, str_buysfrom,(str_buysfrom+"-"+intToStr(cycleNum)));
     }
}

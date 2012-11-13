#include "Graph.h"

Graph::Graph(){

}

std::string Graph::getNodes(){     
    std::string temp;
    for(int i = 0; i < nodes.size(); i++) temp += nodes.at(i);
    return temp;
}

std::string Graph::getEdges(){   
    std::string temp;
    for(int i = 0; i < edges.size(); i++) temp += edges.at(i);
    return temp;
}

std::string Graph::getKeys(){   
    std::string temp;
    for(int i = 0; i < keys.size(); i++) temp += keys.at(i);
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
    keys.push_back(temp);
}

std::string Graph::getDataKey(std::string keyId, std::string value){
    std::string temp = str_datakey;
    find_replace(temp, str_key, keyId);
    find_replace(temp, str_value, value);
    return temp;
}

void Graph::addNode(std::string nodeId, std::vector<std::string> dataKeys){            
    std::string temp = str_node;
    find_replace(temp, str_nodeid, nodeId);
    std::string temp2;
    for(int i = 0; i < dataKeys.size(); i++) temp2 += dataKeys.at(i);
    find_replace(temp,str_datakeys,temp2);    
    nodes.push_back(temp);
}

void Graph::addEdge(std::string edgeId, std::string target, std::string source, std::string label){
    std::string temp = str_edge;
    find_replace(temp, str_edgeid, edgeId);
    find_replace(temp, str_source, source);
    find_replace(temp, str_target, target);
    find_replace(temp, str_label, label);    
    edges.push_back(temp);
}

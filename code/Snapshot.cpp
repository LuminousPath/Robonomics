#include "Snapshot.h"
//#include <libxml/encoding.h>
//#include <libxml/xmlwriter.h>

Snapshot::Snapshot(std::vector<Individual*> unemployedin, std::vector<Firm*> Firmlistin)
{
    unemployed = unemployedin;
    Firmlist = Firmlistin;
}

void Snapshot::print_toscreen()
{
     int population = 0;
     int counter = 0;
     int counter2 = 0;
     std::vector<Firm*>::iterator it = Firmlist.begin();
     Firm* firmpointer;
     std::vector<Individual*>::iterator it2 = unemployed.begin();
     int it3;
     Individual* personpointer;

     for(; it < Firmlist.end(); it++)
     {
           
           firmpointer = *it;
           population += firmpointer->employees.size();
           std::cout << std::endl << "Firm: " << firmpointer->id << std::endl /*<<"Product: "<<firmpointer->companyProduct<<std::endl*/ << "Productivity: " << firmpointer->getproductivity() << std::endl << "Employee Count: " << firmpointer->employees.size() << std::endl << "Capital: " << firmpointer->getcapital() << std::endl<< "Units left: " << firmpointer->unitsLeft << std::endl << "Buys from: " << firmpointer->buysFrom->id<< std::endl;
           /*for(it3 = 0; it3 < firmpointer->getemployees().size(); it3++)
           {
                   personpointer = firmpointer->getemployees().at(it3);
                   std::cout << "Person: " << counter2 + 1 << std::endl << "Productivity: " << personpointer->getproductivity(firmpointer->getcompanyProduct()) << std::endl << "Age: " << personpointer->getage() << std::endl << "lifespan: " << personpointer->getlifespan() << std::endl;
                   counter2++;
           }*/
           counter++;
     }
     std::cout << std::endl<<"Population: " <<population << " Unemployed:" << unemployed.size()  << " Unemployment Rate:"<< (double)unemployed.size()/((double)population + (double) unemployed.size())<< std::endl;
     //std::cin.get();
     /*for(; it2 < unemployed.end(); it2++)
     {
           personpointer = *it2;
           std::cout << "Person: " << counter2 + 1 << std::endl << "Productivity: " << personpointer->getproductivity(NULL) << std::endl << "Age: " << personpointer->getage() << std::endl << "lifespan: " << personpointer->getlifespan() << std::endl;
           counter2++;
     }*/
     
}


/*
void Snapshot::print_toXML(const char *uri)
{
	int rc;
	xmlTextWriterPtr writer;
	xmlChar *temp;

	writer = xmlNewTextWriterFilename(uri, 0);
	if(rc == NULL)
	{
		printf("Snapshot.print_toXML: Error creating the xml writer\n");
		return;
	}

	rc = xmlTextWriterStartDocument(writer, NULL, "UTF-8", NULL);
	if(rc < 0)
	{
		printf("Snapshot.print_toXML: Error at xmlTextWriterStartDocument\n");
		return;
	}

	rc = xmlTextWriterStartElement(writer, BAD_CAST "graphml");
	if(rc < 0)
	{
		printf("Snapshot.print_toXML: Error at xmlTextWriterWriteElement 'graphml'\n");
		return;
	}

	rc = xmlTextWriterWriteAttribute(writer, BAD_CAST "xmlns", BAD_CAST "http://graphml.graphdrawing.org/xmlns");
	rc = xmlTextWriterWriteAttribute(writer, BAD_CAST "xmlns:xsi", BAD_CAST "http://www.w3.org/2001/XMLSchema-instance");
	rc = xmlTextWriterWriteAttribute(writer, BAD_CAST "xsi:schemaLocation", BAD_CAST "http://graphml.graphdrawing.org/xmlns\nhttp://graphml.graphdrawing.org/xmlns/1.0/graphml.xsd");

	rc = xmlTextWriterStartElement(writer, BAD_CAST "graph");
	rc = xmlTextWriterWriteAttribute(writer, BAD_CAST "id", BAD_CAST "Simulation");
	rc = xmlTextWriterWriteAttribute(writer, BAD_CAST "edgedefault", BAD_CAST "undirected");

    char buf[12];
	for(int c = 0; c < Firmlist.size(); c++)
	{
		xmlTextWriterStartElement(writer, BAD_CAST "node");
		snprintf(buf, sizeof(buf), "Firm%d", c);
		xmlTextWriterWriteAttribute(writer, BAD_CAST "id", BAD_CAST(buf));
		xmlTextWriterEndElement(writer);

	}

	rc = xmlTextWriterEndDocument(writer);
	if(rc < 0)
	{
		printf("Snapshot.print_toXML: Error at xmlTextWriterEndDocument\n");
		return;
	}

	xmlFreeTextWriter(writer);
}
*/

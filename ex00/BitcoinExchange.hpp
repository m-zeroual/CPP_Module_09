/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:54:10 by mzeroual          #+#    #+#             */
/*   Updated: 2023/10/18 21:55:35 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <list>
#include <fstream>

class BitcoinExchange : public std::list<std::string>
{
private:
    std::list<std::string>  content;
    std::list<std::string>  date;
    std::list<std::string>  value;
    std::string             name;
    std::string             delimiter;
    std::string             type;
    int                     minValue;
    int                     maxValue;
public:
    void pushContent(const std::string &content)
    {
        this->content.push_back(content);
    }
    void pushDate(const std::string &content)
    {
        this->date.push_back(content);
    }
    void pushValue(const std::string &content)
    {
        this->value.push_back(content);
    }
    void setName(const std::string &name)
    {
        this->name = name;
    }
    void setDelimiter(const std::string &delimiter)
    {
        this->delimiter = delimiter;
    }
    void setType(const std::string &type)
    {
        this->delimiter = type;
    }


    std::list<std::string>& getContent( void )
    {
        return (content);
    }
    const std::list<std::string>& getDate( void ) const
    {
        return (date);
    }
    const std::list<std::string>& getValue( void ) const
    {
        return (value);
    }
    const std::string& getName( void ) const
    {
        return (name);
    }
    const std::string& getDelimiter( void ) const
    {
        return (delimiter);
    }
    const std::string& getType( void ) const
    {
        return (type);
    }
    
    BitcoinExchange( void );
    ~BitcoinExchange( void );
    BitcoinExchange(  std::string name, std::string type, std::string delimiter  );
    
};

BitcoinExchange::BitcoinExchange( void ) : content(0), date(0), value(0), name(0), delimiter(0), type(0), minValue(0), maxValue(1000)
{
}
BitcoinExchange::BitcoinExchange( std::string name, std::string type, std::string delimiter) : content(0), date(0), value(0), name(name), delimiter(delimiter), type(type)
{
    minValue = 0;
    maxValue = 0;
}

BitcoinExchange::~BitcoinExchange( void )
{
}





#endif

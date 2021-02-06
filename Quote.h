#ifndef QUOTE_H
#define QUOTE_H

#include <string>
#include <iostream>
class Quote
{
public:
    Quote() = default;
    virtual Quote *clone() const & { return new Quote(*this); }
    virtual Quote *clone() && { return new Quote(std::move(*this)); }
    Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}
    Quote(const Quote &s) : bookNo(s.bookNo), price(s.price) { std::cout << " Quote(const Quote&)" << std::endl; }
    Quote(const Quote &&s) : bookNo(std::move(s.bookNo)), price(std::move(s.price)) { std::cout << " Quote(const Quote&&)" << std::endl; }
    Quote &operator=(const Quote &s)
    {
        bookNo = s.bookNo;
        price = s.price;
        std::cout << "operator=(const Quote&)" << std::endl;
        return *this;
    }
    Quote &operator=(const Quote &&s)
    {
        if (this != &s)
        {
            bookNo = std::move(s.bookNo);
            price = std::move(s.price);
        }
        std::cout << "operator=(const Quote&&)" << std::endl;
        return *this;
    }
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const { return n * price; }
    virtual void debug(std::ostream &os) const { os << " bookNo: " << bookNo << " price: " << price; }
    virtual ~Quote() { std::cout << "~Quote()" << std::endl; }

private:
    std::string bookNo;

protected:
    double price = 0.0;
};

class Disc_quote : public Quote
{

public:
    Disc_quote() = default;
    Disc_quote(const std::string &book, double price, std::size_t qty, double disc) : Quote(book, price), quantity(qty), discount(disc) {}
    Disc_quote(const Disc_quote &s) : Quote(s), quantity(s.quantity), discount(s.discount) { std::cout << "Disc_quote(const Disc_quote&)" << std::endl; }
    Disc_quote(const Disc_quote &&s) : Quote(std::move(s)), quantity(std::move(s.quantity)), discount(std::move(s.discount)) { std::cout << "Disc_quote(const Disc_quote&&)" << std::endl; }
    Disc_quote &operator=(const Disc_quote &s)
    {
        Quote::operator=(s);
        quantity = s.quantity;
        discount = s.discount;
        std::cout << "operator=(const Disc_quote&)" << std::endl;
        return *this;
    }
    Disc_quote &operator=(const Disc_quote &&s)
    {
        if (this != &s)
        {
            Quote::operator=(std::move(s));
            quantity = std::move(s.quantity);
            discount = std::move(s.discount);
        }
        std::cout << "operator=(const Disc_quote&&)" << std::endl;
        return *this;
    }
    double net_price(std::size_t) const = 0;
    virtual void debug(std::ostream &os) const { os << "Disc_quote"; }
    ~Disc_quote() { std::cout << "~Disc_quote()" << std::endl; }

protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};

class Bulk_quote final : public Disc_quote
{
public:
    Bulk_quote() = default;
    Bulk_quote* clone() const & {return new Bulk_quote(*this);}
    Bulk_quote* clone() && {return new Bulk_quote(std::move(*this));}
    Bulk_quote(const std::string &, double, std::size_t, double);
    Bulk_quote(const Bulk_quote &s) : Disc_quote(s) { std::cout << "Bulk_quote(const Bulk_quote&)" << std::endl; }
    Bulk_quote(const Bulk_quote &&s) : Disc_quote(std::move(s)) { std::cout << "Bulk_quote(const Bulk_quote&&)" << std::endl; }
    Bulk_quote &operator=(const Bulk_quote &s)
    {
        Disc_quote::operator=(s);
        std::cout << "operator=(const Bulk_quote&)" << std::endl;
        return *this;
    }
    Bulk_quote &operator=(const Bulk_quote &&s)
    {
        if (this != &s)
        {
            Disc_quote::operator=(std::move(s));
        }
        std::cout << "operator=(const Bulk_quote&&)" << std::endl;
        return *this;
    }
    double net_price(std::size_t) const override;
    void debug(std::ostream &os) const final { Quote::debug(os), os << " min_pty: " << quantity << " discount: " << discount; }
    ~Bulk_quote() { std::cout << "~Bulk_quote()" << std::endl; }
};

Bulk_quote::Bulk_quote(const std::string &book, double sales_price, std::size_t qty, double disc) : Disc_quote(book, sales_price, qty, disc) {}

double Bulk_quote::net_price(std::size_t cnt) const
{
    if (cnt >= quantity)
        return (cnt - quantity) * price + quantity * (1 - discount) * price;
    else
        return cnt * price * (1 - discount);
}

double print_total(std::ostream &os, const Quote &item, std::size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << "  total due: " << ret << std::endl;
    return ret;
}
#endif // !QUOTE_H
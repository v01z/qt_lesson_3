#ifndef WEBINFO_H
#define WEBINFO_H

#include <QString>
#include <QFile>


struct HostConvention {
    QString hostName;
    QString weatherURL;
    QString weatherRegExpStr;
    QString currencyURL;
    QString currencyRegExpStr;
};

class WebInfo
{
private:
    HostConvention m_hstCnv{};
    QString m_weather{};
    QString m_currency{};
public:
    WebInfo(const QString&);

    const QString getWeather() const;
    const QString getCurrency() const;

    friend void gettingWeather(WebInfo&);
    friend void gettingCurrency(WebInfo&);

    void noInfo(bool);
};


const HostConvention hostConvArr[] =
{
   { "mail.ru",
     "https://pogoda.mail.ru/prognoz/moskva/",
     "mrc__share_title\" content=\"([^\"]+)\"",
     "https://news.mail.ru/currency/src/CBRF/charcode/USD/",
     (R"("RUB\",\"items\":\[\{\"rate\":\"(\d\d).(\d\d)(.*?).*(\d\d).(\d\d)(.*?)EUR")")
    },

    { "yandex.ru",
      "https://yandex.ru/pogoda/",
      "nowcastAlert\":\"(.+),\"icon\":",
      "https://yandex.ru",
      "inline-stocks__value_inner\'>([^<]+)<"
    }
};


#endif // WEBINFO_H

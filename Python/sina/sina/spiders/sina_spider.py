import scrapy

from sina.items import SinaItem


class sinaspiderspider(scrapy.Spider):
    name = "sina_spider"
    allowed_domains = ["news.sina.com.cn"]
    start_urls = ["https://news.sina.com.cn"]

    def parse(self, response):
        a_list = response.xpath("//div[@class='ct_t_01']/h1")
        for a in a_list:
            item = SinaItem()
            item["s_title"] = a.xpath("./a/text()")[0].extract()
            url = a.xpath("./a/@href")[0].extract()
            yield scrapy.Request(url, callback=self.parse_details, meta={"item": item})

    def parse_details(self, response):
        item = response.meta["item"]
        item["l_title"] = response.xpath("//h1[@class='main-title']/text()").extract_first()
        item["publish_time"] = response.xpath("//div[@class='date-source']/span/text()").extract_first()
        print(item["s_title"])
        print(item["l_title"])
        print(item["publish_time"])
        yield item
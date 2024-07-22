# Define here the models for your scraped items
#
# See documentation in:
# https://docs.scrapy.org/en/latest/topics/items.html

import scrapy

class SinaItem(scrapy.Item):
    # Define the fields for your item here like:
    # name = scrapy.Field()
    l_title = scrapy.Field()
    s_title = scrapy.Field()
    publish_time = scrapy.Field()

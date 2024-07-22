# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: https://docs.scrapy.org/en/latest/topics/item-pipeline.html


# useful for handling different item types with a single interface
from itemadapter import ItemAdapter


class SinaPipeline:
    fp = None

    # 重写父类方法:该方法只在爬虫开始的时候调用一次
    def open_spider(self, spider):
        print('开始爬虫>>>')
        self.fp = open('./sina.csv', 'w', encoding='utf-8')

    def process_item(self, item, spider):
        s_title = item['s_title']
        l_title = item['l_title']
        publish_time = item['publish_time']
        self.fp.write(s_title + ',' + l_title + ',' + publish_time + '\n')
        return item

    def close_spider(self, spider):
        print('结束爬虫>>>')
        self.fp.close()
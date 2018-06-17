package com.portfolio.app.Model;

import java.sql.Date;

public class LSM0010VO {	
	private String id;
	private String title;
	private String content;
	private String cre_id;
	private Date cre_dt;
	private String upd_id;
	private Date upd_dt;
	
	public String getId() {
		return id;
	}
	public void setId(String id) {
		this.id = id;
	}
	public String getTitle() {
		return title;
	}
	public void setTitle(String title) {
		this.title = title;
	}
	public String getContent() {
		return content;
	}
	public void setContent(String content) {
		this.content = content;
	}
	public String getCre_id() {
		return cre_id;
	}
	public void setCre_id(String cre_id) {
		this.cre_id = cre_id;
	}
	public String getUpd_id() {
		return upd_id;
	}
	public void setUpd_id(String upd_id) {
		this.upd_id = upd_id;
	}
	public Date getCre_dt() {
		return cre_dt;
	}
	public void setCre_dt(Date cre_dt) {
		this.cre_dt = cre_dt;
	}
	public Date getUpd_dt() {
		return upd_dt;
	}
	public void setUpd_dt(Date upd_dt) {
		this.upd_dt = upd_dt;
	}
}

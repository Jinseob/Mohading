package com.portfolio.app.Model;

import java.util.Date;

public class DC0010VO {	
	private String id;
	private Date ref_dt;
	private String rank;
	private String keyword;
	private String relation_keyword;
	private int trend_idx_1m;
	private int trend_idx_3m;
	private int trend_idx_6m;
	private int trend_idx_12m;
	private String cre_id;
	private Date cre_dt;
	private String upd_id;
	private Date upd_dt;
	
	public String getId() {
		return id == null ? "" : id;
	}
	public void setId(String id) {
		this.id = id;
	}
	public Date getRef_dt() {
		return ref_dt;
	}
	public void setRef_dt(Date ref_dt) {
		this.ref_dt = ref_dt;
	}
	public String getRank() {
		return rank == null ? "" : rank;
	}
	public void setRank(String rank) {
		this.rank = rank;
	}
	public String getKeyword() {
		return keyword == null ? "" : keyword;
	}
	public void setKeyword(String keyword) {
		this.keyword = keyword;
	}
	public String getRelation_keyword() {
		return relation_keyword == null ? "" : relation_keyword;
	}
	public void setRelation_keyword(String relation_keyword) {
		this.relation_keyword = relation_keyword;
	}
	public int getTrend_idx_1m() {
		return trend_idx_1m;
	}
	public void setTrend_idx_1m(int trend_idx_1m) {
		this.trend_idx_1m = trend_idx_1m;
	}
	public int getTrend_idx_3m() {
		return trend_idx_3m;
	}
	public void setTrend_idx_3m(int trend_idx_3m) {
		this.trend_idx_3m = trend_idx_3m;
	}
	public int getTrend_idx_6m() {
		return trend_idx_6m;
	}
	public void setTrend_idx_6m(int trend_idx_6m) {
		this.trend_idx_6m = trend_idx_6m;
	}
	public int getTrend_idx_12m() {
		return trend_idx_12m;
	}
	public void setTrend_idx_12m(int trend_idx_12m) {
		this.trend_idx_12m = trend_idx_12m;
	}
	public String getCre_id() {
		return cre_id == null ? "" : cre_id;
	}
	public void setCre_id(String cre_id) {
		this.cre_id = cre_id;
	}
	public Date getCre_dt() {
		return cre_dt;
	}
	public void setCre_dt(Date cre_dt) {
		this.cre_dt = cre_dt;
	}
	public String getUpd_id() {
		return upd_id == null ? "" : upd_id;
	}
	public void setUpd_id(String upd_id) {
		this.upd_id = upd_id;
	}
	public Date getUpd_dt() {
		return upd_dt;
	}
	public void setUpd_dt(Date upd_dt) {
		this.upd_dt = upd_dt;
	}
}
